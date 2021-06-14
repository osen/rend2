#include "Context.h"
#include "Window.h"
#include "Mesh.h"
#include "Image.h"
#include "sys.h"
#include "UiShader.h"

namespace rend
{

Context::Context(ref<Window> window)
{
  sys = box<SysContext>::make(window->getSys());

  uiShader = box<UiShader>::make(this);
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

box<Image> Context::createImage()
{
  box<Image> rtn = box<Image>::make(this);
  //rtn->context.bind(this);

  return rtn;
}

ref<UiShader> Context::getUiShader()
{
  return uiShader;
}

}

