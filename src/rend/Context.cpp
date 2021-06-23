#include "Context.h"
#include "Window.h"
#include "Mesh.h"
#include "Image.h"
#include "sys.h"
#include "UiShader.h"

namespace rend
{

Context::Context(Ref<Window> window)
{
  sys = Box<SysContext>::make(window->getSys());
}

Ref<SysContext> Context::getSys()
{
  return sys;
}

Box<Mesh> Context::createMesh()
{
  Box<Mesh> rtn = Box<Mesh>::make();
  rtn->context.bind(this);

  return rtn;
}

Box<Image> Context::createImage()
{
  Box<Image> rtn = Box<Image>::make(this);

  return rtn;
}

Ref<UiShader> Context::getUiShader()
{
  if(!uiShader.valid())
  {
    uiShader = Box<UiShader>::make(this);
  }

  return uiShader;
}

}

