#include "Image.h"
#include "Window.h"
#include "Context.h"

namespace rend
{

Image::Image()
{
  sys = box<SysTexture>::make(Window::getInstance()->getContext()->getSys());
}

Image::~Image()
{

}

}

