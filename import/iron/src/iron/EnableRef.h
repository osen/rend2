namespace iron
{

template <typename T>
struct Ref;

struct EnableRef
{
  EnableRef() : m_mut() { getTotal()++; }

  EnableRef(EnableRef const& copy) : m_mut() { getTotal()++; }
  EnableRef& operator=(EnableRef const& other) { return *this; }

  ~EnableRef()
  {
    getTotal()--;

    if(m_mut.m_count > 0)
    {
      panic("Dangling reference remains");
    }
  }

  static int& getTotal()
  {
    static int rtn = 0;

    return rtn;
  }

private:
  template <typename T>
  friend struct Ref;

  mutable struct
  {
    int m_count;
  } m_mut;
};

}

