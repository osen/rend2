namespace iron
{

template <typename T, size_t S>
struct Array
{
  Array();
  ~Array();
  Array(Array const& copy);
  Array &operator=(Array const& other);

  size_t size() const;

  T const& operator[](VectorIndex const& _idx) const;
  T &operator[](VectorIndex const& _idx);

private:
  T m_data[S];
  size_t m_size;
  int mutable m_count;

  void check() const;

};

template <typename T, size_t S>
Array<T, S>::Array() : m_data(), m_size(S), m_count() { }

template <typename T, size_t S>
Array<T, S>::Array(Array<T, S> const& copy) : m_data(copy.m_data), m_size(copy.m_data), m_count() { }

template <typename T, size_t S>
Array<T, S> &Array<T, S>::operator=(Array<T, S> const& other)
{
  // TODO: Optional. Not really needed
  check();
  m_data = other.m_data;
  m_size = other.m_size;
}

template <typename T, size_t S>
Array<T, S>::~Array()
{
  check();
}

template <typename T, size_t S>
size_t Array<T, S>::size() const
{
  return m_size;
}

template <typename T, size_t S>
T const& Array<T, S>::operator[](VectorIndex const& _idx) const
{
  m_count++;
  _idx.m_count = &m_count;

  if(_idx >= m_size)
  {
    panic("Index past end of array");
  }

  return m_data[_idx];
}

template <typename T, size_t S>
T &Array<T, S>::operator[](VectorIndex const& _idx)
{
  m_count++;
  _idx.m_count = &m_count;

  if(_idx >= m_size)
  {
    panic("Index past end of array");
  }

  return m_data[_idx];
}

template <typename T, size_t S>
void Array<T, S>::check() const
{
  if(m_count > 0)
  {
    panic("Attempt to modify vector during access");
  }
}

}

