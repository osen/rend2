#ifndef REND_SYS_H
#define REND_SYS_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <iron>

namespace rend
{

struct SysSdl
{
  SysSdl();
  ~SysSdl();

  static unique<int> count;
};

struct SysWindow
{
  SysWindow();
  ~SysWindow();

  box<SysSdl> sdl;
  unique<SDL_Window *> sys;
};

struct SysContext
{
  SysContext(ref<SysWindow> window);
  ~SysContext();

  ref<SysWindow> window;
  unique<SDL_GLContext> sys;
};

struct SysTexture
{
  SysTexture(ref<SysContext> context);
  ~SysTexture();

  ref<SysContext> context;
  unique<GLuint> sys;
};

struct SysBuffer
{
  SysBuffer(ref<SysContext> context);
  ~SysBuffer();

  ref<SysContext> context;
  unique<GLuint> sys;
};

}

#endif

