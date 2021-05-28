#include "sys.h"

#include <SDL2/SDL.h>
#include <GL/gl.h>

#include <iron>

namespace rend
{

struct Image
{
  Image();
  ~Image();

private:
  box<SysTexture> sys;

};

}
