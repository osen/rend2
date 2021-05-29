#include "sys.h"
#include "Face.h"

#include <iron>

namespace rend
{

struct Context;

struct Mesh
{

  bool hasNormals();
  bool hasTexCoords();
  bool hasPositions();
  void addFace(ref<Face> face);

private:
  friend struct Context;

  ref<Context> context;
  vec<Face> faces;
  box<SysBuffer> positions;
  box<SysBuffer> normals;
  box<SysBuffer> texCoords;
  unique<bool> dirty;

  unique<bool> foundNormal;
  unique<bool> foundTexCoord;
  unique<bool> foundPosition;

};

}

