#include <new>

template <typename T>
struct vec
{
  vec() : curr(), max(), data() { }
  vec(vec const &copy) : curr(), max(), data() { clone(copy); }
  vec &operator=(vec const &other) { if(&other != this) { clone(other); } return *this; }
  ~vec() { wipe(); }

  size_t size() const { return curr; }

  void push(T const &value)
  {
    fit(curr + 1);
    new(&data[curr]) val<T>(value);
    ++curr;
  }

  ref<T> operator[](size_t idx) const
  { 
    if(idx >= curr)
    {
      panic("Index past end of vector");
    }

    return data[idx];
  }

  void clear()
  {
    for(size_t i = 0; i < curr; i++)
    {
      data[i].~val<T>();
    }

    curr = 0;
  }

private:
  size_t curr;
  size_t max;
  val<T> *data;

  void wipe()
  {
    if(!data) return;
 
    for(size_t i = 0; i < curr; i++)
    {
      data[i].~val<T>();
    }

    free(data); data = NULL;
    curr = 0;
    max = 0;
  }

  void fit(size_t req)
  {
    size_t nm = 8;

    if(max >= req) return;

    while(nm < req)
    {
      nm *= 2;
    }

    if(max >= nm) return;

    val<T> *nd = (val<T> *)malloc(nm * sizeof(val<T>));

    for(size_t i = 0; i < curr; i++)
    {
      new(&nd[i]) val<T>(data[i]);
    }

    size_t nc = curr;
    wipe();
    curr = nc;
    data = nd;
    max = nm;
  }

  void clone(vec const &copy)
  {
    wipe();
    fit(copy.curr);

    for(size_t i = 0; i < copy.curr; i++)
    {
      new(&data[i]) val<T>(copy.data[i]);
    }

    curr = copy.curr;
  }
};

