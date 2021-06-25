#include "Mesh.h"
#include "Face.h"

#include <iron>

#include <GL/glew.h>

struct Mesh::Impl : DisableCopy
{
  Vector<Face> m_faces;
  Value<bool> m_dirty;

  Value<GLuint> m_positionId;
  Value<GLuint> m_normalId;
  Value<GLuint> m_texCoordId;
  Value<GLuint> m_lmCoordId;
};
