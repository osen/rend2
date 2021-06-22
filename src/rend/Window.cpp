#include "Window.h"
#include "Context.h"
#include "sys.h"

#ifdef USE_SDL2
  #include <SDL2/SDL.h>
#endif

#include <GL/glew.h>

namespace rend
{

ref<Window> Window::instance;

//ref<Window> Window::getInstance()
//{
//  return instance;
//}

Window::Window()
{
  if(instance.valid())
  {
    panic("Only one window instance allowed");
  }

#ifdef USE_SDL2
  sys = box<SysWindow>::make();
#endif
  context = ::box<Context>::make(this);

  instance.bind(this);
}

Window::~Window()
{
  instance.reset();
}

ref<Context> Window::getContext()
{
  return context;
}

ref<SysWindow> Window::getSys()
{
#ifdef USE_SDL2
  return sys;
#endif
#ifdef USE_FLTK
  return this;
#endif
}

void Window::start()
{
#ifdef USE_SDL2
  SDL_Event e = {0};

  quit = false;

  while(!quit)
  {
    while(SDL_PollEvent(&e))
    {
      if(e.type == SDL_QUIT)
      {
        quit = true;
      }
    }

    onTick();
    display();

    SDL_GL_SwapWindow(sys->sys);
  }
#endif
#ifdef USE_FLTK
  Fl::run();
#endif
}

#ifdef USE_FLTK
void Window::draw()
{
  display();
}
#endif

void Window::stop()
{
  quit = true;
}

void Window::display()
{
  if(!initialized)
  {
    if(glewInit() != GLEW_OK)
    {
      panic("Failed to initialize glew");
    }

    initialized = true;
  }

  //glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
  glClearColor(0.9f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  onDisplay();
}

void Window::onTick() { }
void Window::onDisplay() { }
void Window::onKeyboard() { }
void Window::onMouse() { }

}

