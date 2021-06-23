#include <string.h>

namespace iron
{

struct String
{
  String() { m_data.push(0); }
  //String(String const& _copy) : m_data(_copy.m_data) { }
  //String &operator=(String const& _other) { m_data = _other.m_data; return *this; }

  String(char const* const& _str)
  {
    size_t len = strlen(_str);
    m_data.resize(len + 1);

    for(size_t i = 0; i < len; i++)
    {
      m_data[i] = _str[i];
    }

    // Don't need a null char at end because should be 0
  }

  char& operator[](VectorIndex const& _idx) const
  {
    if(_idx + 1 >= m_data.size())
    {
      panic("Index past end of String");
    }

    return m_data[_idx];
  }

  void append(char _c)
  {
    m_data[m_data.size() - 1] = _c;
    m_data.push(0);
  }

  void append(char const* const& _str)
  {
    size_t len = strlen(_str);
    size_t origSize = m_data.size() - 1;
    m_data.resize(origSize + len + 1);

    for(size_t i = origSize; i < len; i++)
    {
      m_data[i] = _str[i];
    }

    m_data[m_data.size() - 1] = 0;
  }

private:
  Vector<char> m_data;

};

}
