
template <typename T>
struct ref
{
  template <typename U>
  friend struct ref;

  /*
   * ref
   */
  ref() : mut() { }
  ref(const ref &copy) : mut() { reset(copy.mut.raw, copy.mut.count); }
  ref &operator=(const ref &other) { reset(other.mut.raw, other.mut.count); return *this; }
  ~ref() { reset(NULL, NULL); }

  template <typename U>
  ref(const ref<U> &other) : mut() { reset(other.mut.raw, other.mut.count); }
  template <typename U>
  ref &operator=(const ref<U> &other) { reset(other.mut.raw, other.mut.count); return *this; }

  /*
   * val
   */
  ref(const val<T> &value) : mut() { reset(&value.mut.raw, &value.mut.count); }
  ref &operator=(const val<T> &value) { reset(&value.mut.raw, &value.mut.count); return *this; }

  template <typename U>
  ref(const val<U> &value) : mut() { reset(&value.mut.raw, &value.mut.count); }
  template <typename U>
  ref &operator=(const val<U> &value) { reset(&value.mut.raw, &value.mut.count); return *this; }

  /*
   * box
   */
  ref(const box<T> &value) : mut() { reset(value.mut.raw, value.mut.count); }
  ref &operator=(const box<T> &value) { reset(value.mut.raw, value.mut.count); return *this; }

  template <typename U>
  ref(const box<U> &value) : mut() { reset(value.mut.raw, value.mut.count); }
  template <typename U>
  ref &operator=(const box<U> &value) { reset(value.mut.raw, value.mut.count); return *this; }

  /*
   * T
   */
  ref(const T &value) : mut() { *get() = value; }
  ref &operator=(const T &value) { *get() = value; return *this; }

  template <typename U>
  ref(const U &value) : mut() { *get() = value; }
  template <typename U>
  ref &operator=(const U &value) { *get() = value; return *this; }

  /*
   * operators
   */
  T *operator->() const { return get(); }
  T &operator*() const { return *get(); }
  operator T &() const { return *get(); }

private:
  mutable struct Mut
  {
    T *raw;
    int *count;

    Mut() : raw(), count() { }
  } mut;

  T *const &get() const
  {
    if(!mut.count)
    {
      panic("Accessing NULL reference");
    }

    return mut.raw;
  }

  void reset(T *const &raw, int *const &count) const
  {
    if(mut.count) (*mut.count)--;

    mut.raw = raw;
    mut.count = count;

    if(mut.count) (*mut.count)++;
  }

};