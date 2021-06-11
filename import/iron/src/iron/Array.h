namespace iron
{

template <typename T, size_t S>
struct array
{
  array() : m_data(), m_size(S), m_count() { }
  ~array() { check(); }

  size_t size() const { return m_size; }

  const T &operator[](vec_idx const &_idx) const
  {
    m_count++;
    _idx.count = &m_count;

    if(_idx >= m_size)
    {
      panic("Index past end of array");
    }

    return m_data[_idx];
  }

  T &operator[](vec_idx const &_idx)
  {
    m_count++;
    _idx.count = &m_count;

    if(_idx >= m_size)
    {
      panic("Index past end of array");
    }

    return m_data[_idx];
  }

private:
  T m_data[S];
  size_t m_size;
  int mutable m_count;

  void check() const
  {
    if(m_count > 0)
    {
      panic("Attempt to modify vector during access");
    }
  }

};

}

