template <typename T>
struct ref;

template <typename T>
struct unique
{
  template <typename U>
  friend struct unique;

  template <typename U>
  friend struct ref;

  /*
   * unique
   */
  unique() : mut() { }
  ~unique() { check(); }

  /*
   * T
   */
  unique(const T &other) : mut(other) { }
  unique &operator=(const T &other) { reset(other); return *this; }

  template <typename U>
  unique(U &other) : mut(other) { }
  template <typename U>
  unique &operator=(U &other) { reset(other); return *this; }

  /*
   * operators
   */
  T &operator->() const { return mut.raw; }
  T *operator&() const { return &mut.raw; }
  //T &operator*() const { return mut.raw; }
  operator T &() const { return mut.raw; }

private:
  unique(const unique &copy);
  unique &operator=(const unique &other);

  template <typename U>
  unique(const unique<U> &other);
  template <typename U>
  unique &operator=(const unique<U> &other);

  mutable struct Mut
  {
    T raw;
    int count;

    Mut() : raw(), count() { }
    Mut(const T &raw) : raw(raw), count() { }
  } mut;

  void check() const
  {
    if(mut.count)
    {
      panic("Dangling references remain");
    }
  }

  void reset(const T &raw) const
  {
    mut.raw = raw;
  }

};

