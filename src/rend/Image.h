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
  ref<SDL_GLContext> context;
  unique<GLuint> id;

};

}
