#include "Context.h"
#include "Window.h"
#include "Mesh.h"

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

box<Mesh> Context::createMesh()
{
  box<Mesh> rtn = box<Mesh>::make();
  rtn->context.bind(this);

  return rtn;
}

}

