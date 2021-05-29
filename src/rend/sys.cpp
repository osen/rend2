#include "sys.h"

#define LOG(F) \
  printf(F"\n")

namespace rend
{

unique<int> SysSdl::count;

SysSdl::SysSdl()
{
  if(count) return;
  LOG("SDL_Init");
  SDL_Init(SDL_INIT_EVERYTHING);
  count++;
}

SysSdl::~SysSdl()
{
  count--;
  if(count) return;
  LOG("SDL_Quit");
  SDL_Quit();
}

SysWindow::SysWindow()
{
  sdl = box<SysSdl>::make();
  LOG("SDL_CreateWindow");

  sys = SDL_CreateWindow("SDL_Window",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    800, 600,
    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

  if(!sys)
  {
    panic("Failed to create window");
  }
}

SysWindow::~SysWindow()
{
  LOG("SDL_DestroyWindow");
  SDL_DestroyWindow(sys);
}

SysContext::SysContext(ref<SysWindow> window) : window(window)
{
  LOG("SDL_GL_CreateContext");
  sys = SDL_GL_CreateContext(window->sys);

  if(!sys)
  {
    panic("Failed to create context");
  }

  if(glewInit() != GLEW_OK)
  {
    SDL_GL_DeleteContext(sys);
    panic("Failed to initialize glew");
  }
}

SysContext::~SysContext()
{
  LOG("SDL_GL_DeleteContext");
  SDL_GL_DeleteContext(sys);
}

SysTexture::SysTexture(ref<SysContext> context) : context(context)
{
  LOG("glGenTextures");
  glGenTextures(1, &sys);

  if(!sys)
  {
    panic("Failed to create texture");
  }
}

SysTexture::~SysTexture()
{
  LOG("glDeleteTextures");
  glDeleteTextures(1, &sys);
}

SysBuffer::SysBuffer(ref<SysContext> context) : context(context)
{
  LOG("glGenBuffers");
  glGenBuffers(1, &sys);

  if(!sys)
  {
    panic("Failed to create buffer");
  }
}

SysBuffer::~SysBuffer()
{
  LOG("glDeleteBuffers");
  glDeleteBuffers(1, &sys);
}

}

