namespace iron
{

struct DisableCopy
{
  DisableCopy() { }

private:
  DisableCopy(DisableCopy const& copy);
  DisableCopy& operator=(DisableCopy const& other);
};

}
