namespace iron
{

template <typename T>
struct ref;

struct enable_ref
{
  enable_ref() { }

  enable_ref(enable_ref const &copy) { }
  enable_ref &operator=(enable_ref const &other) { return *this; }

  ~enable_ref()
  {
    if(mut.count > 0)
    {
      panic("Dangling reference remains");
    }
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

