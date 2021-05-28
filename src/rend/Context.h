#include "sys.h"

#include <iron>

namespace rend
{

struct Window;

struct Context
{
  Context(ref<Window> window);

  ref<SysContext> getSys();

private:
  box<SysContext> sys;

};

}

