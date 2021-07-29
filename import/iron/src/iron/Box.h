namespace iron
{

template <typename T>
struct Ref;

template <typename T>
struct Box
{
  static Box make();

  template <typename U>
  static Box make(U& _u);

  template <typename U, typename V>
  static Box make(U& _u, V& _v);

  /*
   * Box
   */
  Box();
  ~Box();
  Box(Box const& _copy);
  Box &operator=(Box const& _other);

  template <typename U>
  Box(Box<U> const& _other);

  template <typename U>
  Box &operator=(Box<U> const& _other);

  /*
   * operators
   */
  Ref<T> operator->() const;
  //operator T*() const;

  bool valid() const;
  //T* get(VectorIndex const& idx = VectorIndex(1)) const;
  void reset() const;

private:
  template <typename U>
  friend struct Ref;

  template <typename U>
  friend struct Box;

  mutable T* m_raw;
  mutable void (*m_deleter)(void*);
  mutable int* m_count;

  static void deleter(void* _ptr);
  void check() const;
  void release() const;

};

/******************************************************************************
 * Box
 *
 * Ensure that member variables are initialized.
 ******************************************************************************/
template <typename T>
Box<T>::Box() : m_raw(), m_deleter(), m_count() { }

/******************************************************************************
 * ~Box
 *
 * Final reset of object. This will perform dangle checks and finalize / delete
 * raw and delete count.
 ******************************************************************************/
template <typename T>
Box<T>::~Box()
{
  reset();
}

/******************************************************************************
 * Box - Copy
 *
 * Take exclusive ownership of the data by copying raw, deleter and counter and
 * then releasing the original object.
 ******************************************************************************/
template <typename T>
Box<T>::Box(Box<T> const& _copy) : m_raw(_copy.m_raw), m_deleter(_copy.m_deleter),
  m_count(_copy.m_count)
{
  _copy.release();
}

/******************************************************************************
 * Do the same but with the template version if raw can be implicitly upcasted.
 ******************************************************************************/
template <typename T>
template <typename U>
Box<T>::Box(Box<U> const& _other) : m_raw(_other.m_raw), m_deleter(_other.m_deleter),
  m_count(_other.m_count)
{
  _other.release();
}

/******************************************************************************
 * Box - Assign
 *
 * Ensure that we are not assigning from the same object. Copy across the raw,
 * deleter and counter. Then release the original object.
 ******************************************************************************/
template <typename T>
Box<T> &Box<T>::operator=(Box<T> const& _other)
{
  if(&_other != this)
  {
    reset();
    m_raw = _other.m_raw;
    m_deleter = _other.m_deleter;
    m_count = _other.m_count;
    _other.release();
  }

  return *this;
}

/******************************************************************************
 * Do the same but with the template version if raw can be implicitly upcasted.
 ******************************************************************************/
template <typename T>
template <typename U>
Box<T> &Box<T>::operator=(Box<U> const& _other)
{
  if(_other.m_raw != this->m_raw)
  {
    reset();
    m_raw = _other.m_raw;
    m_deleter = _other.m_deleter;
    m_count = _other.m_count;
    _other.release();
  }

  return *this;
}

/*
template <typename T>
Box<T>::operator T*() const
{
  return get();
}
*/

//template <typename T>
//Ref<T> Box<T>::operator->() const { return *this; }

template <typename T>
Box<T> Box<T>::make()
{
  Box<T> rtn;

  rtn.m_raw = new T();
  rtn.m_deleter = deleter;
  rtn.m_count = new int();

  return rtn;
}

template <typename T>
template <typename U>
Box<T> Box<T>::make(U& _u)
{
  Box<T> rtn;

  rtn.m_raw = new T(_u);
  rtn.m_deleter = deleter;
  rtn.m_count = new int();

  return rtn;
}

template <typename T>
template <typename U, typename V>
Box<T> Box<T>::make(U& _u, V& _v)
{
  Box<T> rtn;

  rtn.m_raw = new T(_u, _v);
  rtn.m_deleter = deleter;
  rtn.m_count = new int();

  return rtn;
}

template <typename T>
bool Box<T>::valid() const
{
  return m_raw;
}

/*
template <typename T>
T* Box<T>::get(VectorIndex const& idx) const
{
  (*m_count)++;
  idx.m_count = m_count;

  if(!m_raw)
  {
    panic("Accessing NULL pointer");
  }

  return m_raw;
}
*/

template <typename T>
void Box<T>::reset() const
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

template <typename T>
void Box<T>::deleter(void* _ptr)
{
  T* t = (T*)_ptr;
  delete t;
}

template <typename T>
void Box<T>::check() const
{
  if(m_count && *m_count)
  {
    panic("Dangling references remain");
  }
}

template <typename T>
void Box<T>::release() const
{
  m_raw = NULL;
  m_deleter = NULL;
  m_count = NULL;
}

}

