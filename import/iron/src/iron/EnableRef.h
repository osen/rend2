namespace iron
{

template <typename T>
struct ref;

struct enable_ref
{
  enable_ref() { getTotal()++; }

  enable_ref(enable_ref const &copy) { getTotal()++; }
  enable_ref &operator=(enable_ref const &other) { return *this; }

  ~enable_ref()
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
  friend struct ref;

  mutable struct Mut
  {
    int count;

    Mut() : count() { }
  } mut;
};

}

