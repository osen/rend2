#include <new>

namespace iron
{

template <typename T>
struct vec;

template <typename T, size_t S>
struct array;

struct vec_idx
{
  vec_idx(size_t const &value) : value(value), count() { }
  ~vec_idx() { (*count)--; }

  operator size_t const &() const { return value; }

private:
  template <typename T>
  friend struct vec;

  template <typename T, size_t S>
  friend struct array;

  size_t value;
  mutable int *count;

  vec_idx(const vec_idx &copy); // : value(copy.value), count() { }
  vec_idx &operator=(const vec_idx &other); // { value = other.value; return *this; }
};

template <typename T>
struct vec
{
  vec() : count(), curr(), max(), data() { }
  vec(vec const &copy) : count(), curr(), max(), data() { clone(copy); }
  vec &operator=(vec const &other) { if(&other != this) { clone(other); } return *this; }
  ~vec() { wipe(); }

  size_t size() const { return curr; }

  void push(T const &value)
  {
    check();

    fit(curr + 1);
    new(&data[curr]) T(value);
    ++curr;
  }

  void resize(size_t newSize)
  {
    check();

    fit(newSize);

    for(size_t i = curr; i < newSize; i++)
    {
      new(&data[i]) T();
    }

    curr = newSize;
  }

  T &operator[](vec_idx const &idx) const
  { 
    count++;
    idx.count = &count;

    if(idx >= curr)
    {
      panic("Index past end of vector");
    }

    return data[idx];
  }

  void clear()
  {
    check();

    for(size_t i = 0; i < curr; i++)
    {
      data[i].~T();
    }

    curr = 0;
  }

private:
  size_t curr;
  size_t max;
  T *data;
  mutable int count;

  void check() const
  {
    if(count > 0)
    {
      panic("Attempt to modify vector during access");
    }
  }

  void wipe()
  {
    check();

    if(!data) return;
 
    for(size_t i = 0; i < curr; i++)
    {
      data[i].~T();
    }

    free(data); data = NULL;
    curr = 0;
    max = 0;
  }

  void fit(size_t req)
  {
    check();

    size_t nm = 8;

    if(max >= req) return;

    while(nm < req)
    {
      nm *= 2;
    }

    if(max >= nm) return;

    T *nd = (T *)malloc(nm * sizeof(T));

    for(size_t i = 0; i < curr; i++)
    {
      new(&nd[i]) T(data[i]);
    }

    size_t nc = curr;
    wipe();
    curr = nc;
    data = nd;
    max = nm;
  }

  void clone(vec const &copy)
  {
    check();

    wipe();
    fit(copy.curr);

    for(size_t i = 0; i < copy.curr; i++)
    {
      new(&data[i]) T(copy.data[i]);
    }

    curr = copy.curr;
  }
};

}

