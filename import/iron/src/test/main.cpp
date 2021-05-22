#include <iron>

struct Employee
{
  val<int> id;

  ~Employee()
  {

  }
};

struct Manager : public Employee
{
  val<int> bonus;

  ~Manager()
  {

  }
};

int main()
{

#include "val.h"
#include "box.h"
#include "vec.h"
#include "file.h"

  return 0;
}

