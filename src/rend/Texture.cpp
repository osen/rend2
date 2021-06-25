#include "Texture.h"
#include "mathutil.h"
#include "Context.h"

#include <iron>
#include <GL/glew.h>

namespace rend
{

struct Texture::Impl : DisableCopy
{
  int m_w;
  int m_h;
  Vector<Color> m_pixels;
  Value<bool> m_dirty;

  mutable Value<GLuint> m_id;
};

Texture::Texture() : m_impl(new Texture::Impl()) { }

void Texture::setSize(int _w, int _h)
{
  if(m_impl->m_w == _w && m_impl->m_h == _h) return;

  m_impl->m_dirty = true;
  m_impl->m_pixels.resize(_w * _h);
  m_impl->m_w = _w;
  m_impl->m_h = _h;
}

void Texture::setPixel(int _x, int _y, Color const& _color)
{
  m_impl->m_dirty = true;
  m_impl->m_pixels[_y * m_impl->m_w + _x] = _color;
}

void Texture::load(std::string const& _path)
{
  m_impl->m_dirty = true;
  setSize(128, 128);
}

GLuint Context::getId(Texture const& texture)
{
  return texture.m_impl->m_id;
}

}

