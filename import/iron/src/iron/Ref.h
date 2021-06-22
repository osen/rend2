namespace iron
{

template <typename T>
struct Ref
{
  template <typename U>
  friend struct Ref;

  /*
   * Ref
   */
  Ref() : mut() { }
  Ref(Ref const& copy) : mut(copy.mut.raw, copy.mut.count) { if(mut.count) (*mut.count)++; }
  Ref &operator=(Ref const& other) { *get() = other; return *this; }
  ~Ref() { reset(); }
  void bind(Ref const& other) { reset(other.mut.raw, other.mut.count); }

  template <typename U>
  Ref(Ref<U> const& other) : mut(other.mut.raw, other.mut.count) { if(mut.count) (*mut.count)++; }
  template <typename U>
  Ref &operator=(Ref<U> const& other) { *get() = other; return *this; }
  template <typename U>
  void bind(Ref<U> const& other) { reset(other.mut.raw, other.mut.count); }

  /*
   * Value
   */
  Ref(Value<T> const& value) : mut(&value.mut.raw, &value.mut.count) { if(mut.count) (*mut.count)++; }
  Ref &operator=(Value<T> const& other) { *get() = other; return *this; }
  void bind(Value<T> const& value) { reset(&value.mut.raw, &value.mut.count); }

  template <typename U>
  Ref(Value<U> const& value) : mut(&value.mut.raw, &value.mut.count) { if(mut.count) (*mut.count)++; }
  template <typename U>
  Ref &operator=(Value<U> const& other) { *get() = other; return *this; }
  template <typename U>
  void bind(Value<U> const& value) { reset(&value.mut.raw, &value.mut.count); }

  /*
   * Box
   */
  Ref(Box<T> const& value) : mut(value.m_raw, value.m_count) { if(mut.count) (*mut.count)++; }
  Ref &operator=(Box<T> const& other) { *get() = other; return *this; }
  void bind(Box<T> const& value) { reset(value.m_raw, value.m_count); }

  template <typename U>
  Ref(Box<U> const& value) : mut(value.m_raw, value.m_count) { if(mut.count) (*mut.count)++; }
  template <typename U>
  Ref &operator=(Box<U> const& other) { *get() = other; return *this; }
  template <typename U>
  void bind(Box<U> const& value) { reset(value.m_raw, value.m_count); }

  /*
   * T : EnableRef
   */
  Ref(T* const& value) : mut(value, &value->mut.count) { (*mut.count)++; }
  void bind(T* const& value) { reset(value, &value->mut.count); }
  Ref &operator=(T const& value) { *get() = value; return *this; }

  template <typename U>
  Ref(U* const& value) : mut(value, &value->mut.count) { (*mut.count)++; }
  template <typename U>
  void bind(U* const& value) { reset(value, &value->mut.count); }
  template <typename U>
  Ref &operator=(U const& value) { *get() = value; return *this; }

  /*
   * operators
   */
  T *operator->() const { return get(); }
  //T &operator->() const { return *get(); }
  //T *operator&() const { return get(); }
  //T &operator*() const { return *get(); }
  operator T&() const { return *get(); }

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
    Mut(T* const& raw, int* const& count) : raw(raw), count(count) { }
  } mut;

  T* const& get() const
  {
    if(!mut.count)
    {
      panic("Accessing NULL reference");
    }

    return mut.raw;
  }

  void reset(T* const& raw, int* const& count) const
  {
    reset();

    mut.raw = raw;
    mut.count = count;

    if(mut.count) (*mut.count)++;
  }

};

template <typename T>
Ref<T> Box<T>::operator->() const { return *this; }

}

