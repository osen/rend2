#ifndef REND_SYS_H
#define REND_SYS_H

#include <SDL2/SDL.h>

#include <iron>

namespace rend
{

struct SysSdl
{
  SysSdl();
  ~SysSdl();
};

struct SysWindow
{
  SysWindow(ref<SysSdl> sdl);
  ~SysWindow();

//private:
  ref<SysSdl> sdl;
  unique<SDL_Window *> sys;
};

struct SysContext
{
  SysContext(ref<SysWindow> window);
  ~SysContext();

//private:
  ref<SysWindow> window;
  unique<SDL_GLContext> sys;
};

}

#endif

