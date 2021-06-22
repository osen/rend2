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

  Box(Box const &copy) : m_raw(copy.m_raw), m_deleter(copy.m_deleter),
    m_count(copy.m_count) { copy.release(); }

  Box &operator=(Box const &other) { if(&other != this) { reset();
    m_raw = other.m_raw; m_deleter = other.m_deleter; m_count = other.m_count;
    other.release(); } return *this; }

  template <typename U>
  Box(Box<U> const &other) : m_raw(other.m_raw), m_deleter(other.m_deleter),
    m_count(other.m_count) { other.release(); }

  template <typename U>
  Box &operator=(Box<U> const &other) { if(other.m_raw != this->m_raw) { reset();
    m_raw = other.m_raw; m_deleter = other.m_deleter; m_count = other.m_count;
    other.release(); } return *this; }

  /*
   * operators
   */
  Ref<T> operator->() const;
  operator T *() const { return get(); }

  static Box make()
  {
    Box rtn;

    rtn.m_raw = new T();
    rtn.m_deleter = deleter;
    rtn.m_count = new int();

    return rtn;
  }

  template <typename U>
  static Box make(U &u)
  {
    Box rtn;

    rtn.m_raw = new T(u);
    rtn.m_deleter = deleter;
    rtn.m_count = new int();

    return rtn;
  }

  template <typename U>
  static Box make(U const &u)
  {
    Box rtn;

    rtn.m_raw = new T(u);
    rtn.m_deleter = deleter;
    rtn.m_count = new int();

    return rtn;
  }

  template <typename U, typename V>
  static Box make(U &u, V &v)
  {
    Box rtn;

    rtn.m_raw = new T(u, v);
    rtn.m_deleter = deleter;
    rtn.m_count = new int();

    return rtn;
  }

  template <typename U, typename V>
  static Box make(U const &u, V const &v)
  {
    Box rtn;

    rtn.m_raw = new T(u, v);
    rtn.m_deleter = deleter;
    rtn.m_count = new int();

    return rtn;
  }


  bool valid() const
  {
    return m_raw;
  }

  T *get() const
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
      m_deleter((void *)m_raw);
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

  T mutable *m_raw;
  mutable void (*m_deleter)(void *);
  int mutable *m_count;

  static void deleter(void *ptr)
  {
    T *t = (T *)ptr;
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

