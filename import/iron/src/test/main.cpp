#include <iron>

struct Employee : enable_ref
{
  val<int> id;

  ~Employee()
  {

  }

  void vec_sink(vec<box<Employee> > &emps)
  {
    emps.clear();
  }

  void box_sink(box<Employee> &emp)
  {
    emp.reset();
  }
};

struct Manager : public Employee
{
  val<int> bonus;

  ~Manager()
  {

  }
};

#include "misc.h"

int main()
{

#include "val.h"
#include "box.h"
#include "vec.h"
#include "arr.h"
#include "string.h"
#include "file.h"
#include "enable_ref.h"

  run_misc();

  return 0;
}

