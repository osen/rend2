#include "draw.h"

#include <GL/glew.h>

namespace rend
{

void clear(Color const& _color)
{
  glClearColor(_color.r, _color.g, _color.b, _color.a);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void draw(Texture const& _texture, Vec2 const& _position, float rotation,
  Vec2 const& _scale)
{

}

}
