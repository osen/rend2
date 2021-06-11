namespace iron
{

template <typename T>
struct ref;

template <typename T>
struct box
{
  /*
   * box
   */
  box() : mut() { }
  box(const box &copy) : mut(copy.mut.raw, copy.mut.deleter, copy.mut.count) { copy.release(); }
  box &operator=(const box &other) { if(&other != this) { reset(); mut = Mut(other.mut.raw, other.mut.deleter, other.mut.count); other.release(); } return *this; }
  ~box() { reset(); }

  template <typename U>
  box(const box<U> &other) : mut(other.mut.raw, other.mut.deleter, other.mut.count) { other.release(); }
  template <typename U>
  box &operator=(const box<U> &other) { if((void *)&other != (void *)this) { reset(); mut = Mut(other.mut.raw, other.mut.deleter, other.mut.count); other.release(); } return *this; }

  /*
   * operators
   */
  //T *operator->() const { return get(); }
  ref<T> operator->() const;
  operator T *() const { return get(); }

  static box make()
  {
    box rtn;

    rtn.mut.raw = new T();
    rtn.mut.deleter = deleter;
    rtn.mut.count = new int();

    return rtn;
  }

  template <typename U>
  static box make(U &u)
  {
    box rtn;

    rtn.mut.raw = new T(u);
    rtn.mut.deleter = deleter;
    rtn.mut.count = new int();

    return rtn;
  }

  template <typename U>
  static box make(U const &u)
  {
    box rtn;

    rtn.mut.raw = new T(u);
    rtn.mut.deleter = deleter;
    rtn.mut.count = new int();

    return rtn;
  }

  bool valid() const
  {
    return mut.raw;
  }

  T *get() const
  {
    if(!mut.raw)
    {
      panic("Accessing NULL pointer");
    }

    return mut.raw;
  }

  void reset() const
  {
    check();

    if(mut.deleter && mut.raw)
    {
      mut.deleter((void *)mut.raw);
    }

    if(mut.count)
    {
      delete mut.count;
    }

    release();
  }

private:
  template <typename U>
  friend struct ref;

  template <typename U>
  friend struct box;

  mutable struct Mut
  {
    T *raw;
    void (*deleter)(void *);
    int *count;

    Mut() : raw(), deleter(), count() { }
    Mut(T *const &raw, void (*const &deleter)(void *), int *const &count) : raw(raw), deleter(deleter), count(count) { }
  } mut;

  static void deleter(void *ptr)
  {
    T *t = (T *)ptr;
    delete t;
  }

  void check() const
  {
    if(mut.count && *mut.count)
    {
      panic("Dangling references remain");
    }
  }

  void release() const
  {
    mut.raw = NULL;
    mut.deleter = NULL;
    mut.count = NULL;
  }

};

//template <typename T>
//ref<T> box<T>::operator->() const { return *this; }

}

