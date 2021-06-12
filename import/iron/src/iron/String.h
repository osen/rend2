#include <string.h>

namespace iron
{

struct string
{
  string() { m_data.push(0); }
  //string(string const &copy) : m_data(copy.m_data) { }
  //string &operator=(string const &other) { m_data = other.m_data; return *this; }

  string(char const * const &str)
  {
    size_t len = strlen(str);
    m_data.resize(len + 1);

    for(size_t i = 0; i < len; i++)
    {
      m_data[i] = str[i];
    }

    // Don't need a null char at end because should be 0
  }

  char &operator[](size_t idx) const
  {
    if(idx + 1 >= m_data.size())
    {
      panic("Index past end of string");
    }

    return m_data[idx];
  }

  void append(char c)
  {
    m_data[m_data.size() - 1] = c;
    m_data.push(0);
  }

  void append(char const * const &str)
  {
    size_t len = strlen(str);
    size_t origSize = m_data.size() - 1;
    m_data.resize(origSize + len + 1);

    for(size_t i = origSize; i < len; i++)
    {
      m_data[i] = str[i];
    }

    m_data[m_data.size() - 1] = 0;
  }

private:
  vec<char> m_data;

};

}
