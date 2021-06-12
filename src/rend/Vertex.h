#ifndef REND_VERTEX_H
#define REND_VERTEX_H

#include "mathutil.h"

#include <iron>

namespace rend
{

struct Vertex
{
  Vec3 position;
  Vec2 texCoord;
  Vec2 lmCoord;
  Vec3 normal;
};

}

#endif

