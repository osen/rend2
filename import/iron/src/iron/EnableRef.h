namespace iron
{

template <typename T>
struct Ref;

struct EnableRef
{
  EnableRef() { getTotal()++; }

  EnableRef(EnableRef const &copy) { getTotal()++; }
  EnableRef &operator=(EnableRef const &other) { return *this; }

  ~EnableRef()
  {
    getTotal()--;

    if(mut.count > 0)
    {
      panic("Dangling reference remains");
    }
  }

  static int &getTotal()
  {
    static int rtn = 0;

    return rtn;
  }

private:
  template <typename T>
  friend struct Ref;

  mutable struct Mut
  {
    int count;

    Mut() : count() { }
  } mut;
};

}

