#include <iron>

struct Employee : EnableRef
{
  Value<int> id;

  ~Employee()
  {

  }

  void vec_sink(Vector<Box<Employee> > &emps)
  {
    emps.clear();
  }

  void box_sink(Box<Employee> &emp)
  {
    emp.reset();
  }
};

struct Manager : public Employee
{
  Value<int> bonus;

  ~Manager()
  {

  }
};

#include "misc.h"

int main()
{

  {
#include "val.h"
#include "box.h"
#include "vec.h"
#include "arr.h"
#include "string.h"
#include "file.h"
#include "enable_ref.h"
  }

  run_misc();

  //printf("Remaining: %i\n", EnableRef::getTotal());

  return 0;
}

