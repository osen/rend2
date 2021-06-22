#ifndef REND_SYS_H
#define REND_SYS_H

#ifdef USE_SDL2
  #include <SDL2/SDL.h>
#endif
#ifdef USE_FLTK
  #include <FL/Fl.H>
  #include <FL/Fl_Gl_Window.H>
#endif

#include <GL/glew.h>

#include <iron>

#define SYS_LOG(F) \
  printf(F"\n")

namespace rend
{

#ifdef USE_SDL2
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

    //if(glewInit() != GLEW_OK)
    //{
    //  SDL_GL_DeleteContext(sys);
    //  panic("Failed to initialize glew");
    //}
  }

  ~SysContext()
  {
    SYS_LOG("SDL_GL_DeleteContext");
    SDL_GL_DeleteContext(sys);
  }

  ref<SysWindow> window;
  unique<SDL_GLContext> sys;
};
#endif

#ifdef USE_FLTK
struct SysWindow : Fl_Gl_Window, enable_ref
{
  SysWindow() : Fl_Gl_Window(800, 600)
  {
    SYS_LOG("Fl_Gl_Window");
    resizable(this);
    end();
    show();
  }

  ~SysWindow()
  {
    SYS_LOG("~Fl_Gl_Window");
  }
};

struct SysContext
{
  SysContext(ref<SysWindow> window) : window(window)
  {
    //if(glewInit() != GLEW_OK)
    //{
    //  panic("Failed to initialize glew");
    //}
  }

  ref<SysWindow> window;
};
#endif

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

struct SysShader
{
  SysShader(ref<SysContext> context, bool isFragment) : context(context)
  {
    SYS_LOG("glCreateShader");

    if(isFragment)
    {
      sys = glCreateShader(GL_FRAGMENT_SHADER);
    }
    else
    {
      sys = glCreateShader(GL_VERTEX_SHADER);
    }

    if(!sys)
    {
      panic("Failed to create shader");
    }
  }

  ~SysShader()
  {
    SYS_LOG("glDeleteShader");
    glDeleteShader(sys);
  }

  ref<SysContext> context;
  unique<GLuint> sys;
};

struct SysProgram
{
  SysProgram(ref<SysContext> context) : context(context)
  {
    SYS_LOG("glCreateProgram");
    sys = glCreateProgram();

    if(!sys)
    {
      panic("Failed to create program");
    }
  }

  ~SysProgram()
  {
    SYS_LOG("glDeleteProgram");
    glDeleteProgram(sys);
  }

  ref<SysContext> context;
  unique<GLuint> sys;
};

}

#endif

