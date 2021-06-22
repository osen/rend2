namespace iron
{

template <typename T>
struct Ref;

template <typename T>
struct Value
{
  template <typename U>
  friend struct Value;

  template <typename U>
  friend struct Ref;

  /*
   * Value
   */
  Value() : mut() { }
  Value(Value const& copy) : mut(copy.mut.raw) { }
  Value &operator=(Value const& other) { mut.raw = other.mut.raw; return *this; }
  ~Value() { check(); }

  template <typename U>
  Value(Value<U> const& other) : mut(other.mut.raw) { }
  template <typename U>
  Value &operator=(Value<U> const& other) { mut.raw = other.mut.raw; return *this; }

  /*
   * T
   */
  Value(T const& t) : mut(t) { }
  Value &operator=(T const& t) { mut.raw = t; return *this; }

  template <typename U>
  Value(U &u) : mut(u) { }
  template <typename U>
  Value &operator=(U &u) { mut.raw = u; return *this; }

  /*
   * operators
   */
  T *operator->() const { return &mut.raw; }
  T *operator&() const { return &mut.raw; }
  operator T &() const { return mut.raw; }

private:

  mutable struct Mut
  {
    T raw;
    int count;

    Mut() : raw(), count() { }
    Mut(T const& raw) : raw(raw), count() { }
  } mut;

  void check() const
  {
    if(mut.count)
    {
      panic("Dangling references remain");
    }
  }

};

}

