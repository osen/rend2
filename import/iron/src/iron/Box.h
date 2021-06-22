namespace iron
{

template <typename T>
struct Ref;

template <typename T>
struct Box
{
  /*
   * Box
   */
  Box() : m_raw(), m_deleter(), m_count() { }
  ~Box() { reset(); }

  Box(Box const& _copy) : m_raw(_copy.m_raw), m_deleter(_copy.m_deleter),
    m_count(_copy.m_count) { _copy.release(); }

  Box &operator=(Box const& _other) { if(&_other != this) { reset();
    m_raw = _other.m_raw; m_deleter = _other.m_deleter; m_count = _other.m_count;
    _other.release(); } return *this; }

  template <typename U>
  Box(Box<U> const& _other) : m_raw(_other.m_raw), m_deleter(_other.m_deleter),
    m_count(_other.m_count) { _other.release(); }

  template <typename U>
  Box &operator=(Box<U> const& _other) { if(_other.m_raw != this->m_raw) { reset();
    m_raw = _other.m_raw; m_deleter = _other.m_deleter; m_count = _other.m_count;
    _other.release(); } return *this; }

  /*
   * operators
   */
  Ref<T> operator->() const;
  operator T*() const { return get(); }

  static Box make()
  {
    Box rtn;

    rtn.m_raw = new T();
    rtn.m_deleter = deleter;
    rtn.m_count = new int();

    return rtn;
  }

  template <typename U>
  static Box make(U& _u)
  {
    Box rtn;

    rtn.m_raw = new T(_u);
    rtn.m_deleter = deleter;
    rtn.m_count = new int();

    return rtn;
  }

  template <typename U>
  static Box make(U const& _u)
  {
    Box rtn;

    rtn.m_raw = new T(_u);
    rtn.m_deleter = deleter;
    rtn.m_count = new int();

    return rtn;
  }

  template <typename U, typename V>
  static Box make(U& _u, V& _v)
  {
    Box rtn;

    rtn.m_raw = new T(_u, _v);
    rtn.m_deleter = deleter;
    rtn.m_count = new int();

    return rtn;
  }

  template <typename U, typename V>
  static Box make(U const& _u, V const& _v)
  {
    Box rtn;

    rtn.m_raw = new T(_u, _v);
    rtn.m_deleter = deleter;
    rtn.m_count = new int();

    return rtn;
  }

  bool valid() const
  {
    return m_raw;
  }

  T* get() const
  {
    if(!m_raw)
    {
      panic("Accessing NULL pointer");
    }

    return m_raw;
  }

  void reset() const
  {
    check();

    if(m_deleter && m_raw)
    {
      m_deleter((void*)m_raw);
    }

    if(m_count)
    {
      delete m_count;
    }

    release();
  }

private:
  template <typename U>
  friend struct Ref;

  template <typename U>
  friend struct Box;

  mutable T* m_raw;
  mutable void (*m_deleter)(void*);
  mutable int* m_count;

  static void deleter(void* _ptr)
  {
    T* t = (T*)_ptr;
    delete t;
  }

  void check() const
  {
    if(m_count && *m_count)
    {
      panic("Dangling references remain");
    }
  }

  void release() const
  {
    m_raw = NULL;
    m_deleter = NULL;
    m_count = NULL;
  }

};

//template <typename T>
//Ref<T> Box<T>::operator->() const { return *this; }

}

