#include "Face.h"

#include <iron>

#include <memory>

namespace rend
{

struct SysBuffer;
struct Context;

struct Mesh
{
  bool hasNormals();
  bool hasTexCoords();
  bool hasPositions();
  void addFace(Ref<Face> face);

private:
  friend struct Context;
  struct Impl;
  std::shared_ptr<Impl> m_impl;

  Ref<Context> context;
  Vector<Face> faces;
  Box<SysBuffer> positions;
  Box<SysBuffer> normals;
  Box<SysBuffer> texCoords;
  Value<bool> dirty;

  Value<bool> foundNormal;
  Value<bool> foundTexCoord;
  Value<bool> foundPosition;

};

}

