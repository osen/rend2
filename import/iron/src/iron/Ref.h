template <typename T>
struct ref
{
  template <typename U>
  friend struct ref;

  /*
   * ref
   */
  ref() : mut() { }
  ref(const ref &copy) : mut(copy.mut.raw, copy.mut.count) { if(mut.count) (*mut.count)++; }
  ref &operator=(const ref &other) { *get() = other; return *this; }
  ~ref() { reset(); }
  void bind(const ref &other) { reset(other.mut.raw, other.mut.count); }

  template <typename U>
  ref(const ref<U> &other) : mut(other.mut.raw, other.mut.count) { if(mut.count) (*mut.count)++; }
  template <typename U>
  ref &operator=(const ref<U> &other) { *get() = other; return *this; }
  template <typename U>
  void bind(const ref<U> &other) { reset(other.mut.raw, other.mut.count); }

  /*
   * val
   */
  ref(const val<T> &value) : mut(&value.mut.raw, &value.mut.count) { if(mut.count) (*mut.count)++; }
  ref &operator=(const val<T> &other) { *get() = other; return *this; }
  void bind(const val<T> &value) { reset(&value.mut.raw, &value.mut.count); }

  template <typename U>
  ref(const val<U> &value) : mut(&value.mut.raw, &value.mut.count) { if(mut.count) (*mut.count)++; }
  template <typename U>
  ref &operator=(const val<U> &other) { *get() = other; return *this; }
  template <typename U>
  void bind(const val<U> &value) { reset(&value.mut.raw, &value.mut.count); }

  /*
   * unique
   */
  ref(const unique<T> &other) : mut(&other.mut.raw, &other.mut.count) { if(mut.count) (*mut.count)++; }
  ref &operator=(const unique<T> &other) { *get() = other; return *this; }
  void bind(const unique<T> &other) { reset(&other.mut.raw, &other.mut.count); }

  template <typename U>
  ref(const unique<U> &other) : mut(&other.mut.raw, &other.mut.count) { if(mut.count) (*mut.count)++; }
  template <typename U>
  ref &operator=(const unique<U> &other) { *get() = other; return *this; }
  template <typename U>
  void bind(const unique<U> &other) { reset(&other.mut.raw, &other.mut.count); }

  /*
   * box
   */
  ref(const box<T> &value) : mut(value.mut.raw, value.mut.count) { if(mut.count) (*mut.count)++; }
  ref &operator=(const box<T> &other) { *get() = other; return *this; }
  void bind(const box<T> &value) { reset(value.mut.raw, value.mut.count); }

  template <typename U>
  ref(const box<U> &value) : mut(value.mut.raw, value.mut.count) { if(mut.count) (*mut.count)++; }
  template <typename U>
  ref &operator=(const box<U> &other) { *get() = other; return *this; }
  template <typename U>
  void bind(const box<U> &value) { reset(value.mut.raw, value.mut.count); }

  /*
   * T : enable_ref
   */
  ref(T *const &value) : mut(value, &value->mut.count) { (*mut.count)++; }
  void bind(T *const &value) { reset(value, &value->mut.count); }
  ref &operator=(T const &value) { *get() = value; return *this; }

  template <typename U>
  ref(U *const &value) : mut(value, &value->mut.count) { (*mut.count)++; }
  template <typename U>
  void bind(U *const &value) { reset(value, &value->mut.count); }
  template <typename U>
  ref &operator=(U const &value) { *get() = value; return *this; }

  /*
   * operators
   */
  T *operator->() const { return get(); }
  //T &operator->() const { return *get(); }
  //T *operator&() const { return get(); }
  //T &operator*() const { return *get(); }
  operator T &() const { return *get(); }

  bool valid() const
  {
    return mut.raw;
  }

  void reset() const
  {
    if(mut.count) (*mut.count)--;
    mut.raw = NULL;
    mut.count = NULL;
  }

private:
  mutable struct Mut
  {
    T *raw;
    int *count;

    Mut() : raw(), count() { }
    Mut(T *const &raw, int *const &count) : raw(raw), count(count) { }
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
    reset();

    mut.raw = raw;
    mut.count = count;

    if(mut.count) (*mut.count)++;
  }

};

template <typename T>
ref<T> box<T>::operator->() const { return *this; }

