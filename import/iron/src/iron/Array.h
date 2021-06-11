template <typename T, size_t S>
struct arr
{
  arr() : data(), _size(S), count() { }
  ~arr() { check(); }

  size_t size() { return _size; }

private:
  T data[S];
  size_t _size;
  mutable int count;

  void check() const
  {
    if(count > 0)
    {
      panic("Attempt to modify vector during access");
    }
  }

};
