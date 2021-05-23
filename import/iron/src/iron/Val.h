template <typename T>
struct ref;

template <typename T>
struct val
{
  template <typename U>
  friend struct val;

  template <typename U>
  friend struct ref;

  /*
   * val
   */
  val() : mut() { }
  val(const val &copy) : mut(copy.mut.raw) { }
  val &operator=(const val &other) { reset(other.mut.raw); return *this; }
  ~val() { check(); }

  template <typename U>
  val(const val<U> &other) : mut(other.mut.raw) { }
  template <typename U>
  val &operator=(const val<U> &other) { reset(other.mut.raw); return *this; }

  /*
   * T
   */
  val(const T &value) : mut(value) { }
  val &operator=(const T &value) { reset(value); return *this; }

  template <typename U>
  val(U &value) : mut(value) { }
  template <typename U>
  val &operator=(U &value) { reset(value); return *this; }

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

