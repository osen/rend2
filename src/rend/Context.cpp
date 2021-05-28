#include "Context.h"
#include "Window.h"

namespace rend
{

Context::Context(ref<Window> window)
{
  sys = box<SysContext>::make(window->getSys());
}

ref<SysContext> Context::getSys()
{
  return sys;
}

}

