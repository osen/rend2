#include "mathutil.h"

#include <iron>

namespace rend
{

struct Vec2;
struct Texture;

void clear(Color const& _color = Color(1, 0, 0));

void draw(
  Texture const& _texture,
  Vec2 const& _position,
  float rotation = 0,
  Vec2 const& _scale = Vec2(1, 1)
);

}
