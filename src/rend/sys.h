#ifndef REND_SYS_H
#define REND_SYS_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <iron>

#define SYS_LOG(F) \
  printf(F"\n")

namespace rend
{

struct SysSdl
{
  SysSdl()
  {
    if(getCount() == 0)
    {
      SYS_LOG("SDL_Init");
      SDL_Init(SDL_INIT_EVERYTHING);
    }

    getCount()++;
  }

  ~SysSdl()
  {
    getCount()--;

    if(getCount() == 0)
    {
      SYS_LOG("SDL_Quit");
      SDL_Quit();
    }
  }

  static int &getCount()
  {
    static int count = 0;

    return count;
  }
};

struct SysWindow
{
  SysWindow()
  {
    sdl = box<SysSdl>::make();
    SYS_LOG("SDL_CreateWindow");

    sys = SDL_CreateWindow("SDL_Window",
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      800, 600,
      SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if(!sys)
    {
      panic("Failed to create window");
    }
  }

  ~SysWindow()
  {
    SYS_LOG("SDL_DestroyWindow");
    SDL_DestroyWindow(sys);
  }

  box<SysSdl> sdl;
  unique<SDL_Window *> sys;
};

struct SysContext
{
  SysContext(ref<SysWindow> window) : window(window)
  {
    SYS_LOG("SDL_GL_CreateContext");
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

  ~SysContext()
  {
    SYS_LOG("SDL_GL_DeleteContext");
    SDL_GL_DeleteContext(sys);
  }

  ref<SysWindow> window;
  unique<SDL_GLContext> sys;
};

struct SysTexture
{
  SysTexture(ref<SysContext> context) : context(context)
  {
    SYS_LOG("glGenTextures");
    glGenTextures(1, &sys);

    if(!sys)
    {
      panic("Failed to create texture");
    }
  }

  ~SysTexture()
  {
    SYS_LOG("glDeleteTextures");
    glDeleteTextures(1, &sys);
  }

  ref<SysContext> context;
  unique<GLuint> sys;
};

struct SysBuffer
{
  SysBuffer(ref<SysContext> context) : context(context)
  {
    SYS_LOG("glGenBuffers");
    glGenBuffers(1, &sys);

    if(!sys)
    {
      panic("Failed to create buffer");
    }
  }

  ~SysBuffer()
  {
    SYS_LOG("glDeleteBuffers");
    glDeleteBuffers(1, &sys);
  }

  ref<SysContext> context;
  unique<GLuint> sys;
};

}

#endif

