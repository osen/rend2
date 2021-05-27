#include "sys.h"

namespace rend
{

SysSdl::SysSdl()
{
  printf("SDL_Init\n");
  SDL_Init(SDL_INIT_EVERYTHING);
}

SysSdl::~SysSdl()
{
  printf("SDL_Quit\n");
  SDL_Quit();
}

SysWindow::SysWindow(ref<SysSdl> sdl)
{
  printf("SDL_CreateWindow\n");
  this->sdl = sdl;

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
  printf("SDL_DestroyWindow\n");
  SDL_DestroyWindow(sys);
}

SysContext::SysContext(ref<SysWindow> window)
{
  printf("SDL_GL_CreateContext\n");
  this->window = window;
  sys = SDL_GL_CreateContext(window->sys);

  if(!sys)
  {
    panic("Failed to create context");
  }
}

SysContext::~SysContext()
{
  printf("SDL_GL_DeleteContext\n");
  SDL_GL_DeleteContext(sys);
}

}

