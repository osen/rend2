#include "Image.h"
#include "Window.h"

namespace rend
{

Image::Image()
{
  context = Window::getInstance()->getContext();
  glGenTextures(1, &id);

  if(!id)
  {
    panic("Failed to create texture");
  }
}

Image::~Image()
{
  glDeleteTextures(1, &id);
}

}

