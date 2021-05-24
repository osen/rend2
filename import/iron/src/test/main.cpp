#include <iron>

struct Employee : enable_ref
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
#include "enable_ref.h"

  return 0;
}

