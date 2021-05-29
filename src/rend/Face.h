#ifndef REND_FACE_H
#define REND_FACE_H

#include "Vertex.h"

#include <iron>

namespace rend
{

struct Face
{
  Vertex a;
  Vertex b;
  Vertex c;
};

}

#endif

