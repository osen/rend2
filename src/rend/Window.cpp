#include "Window.h"
#include "Context.h"
#include "sys.h"

#ifdef USE_SDL2
  #include <SDL2/SDL.h>
#endif

#include <GL/glew.h>

namespace rend
{

Ref<Window> Window::instance;

//Ref<Window> Window::getInstance()
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
  sys = Box<SysWindow>::make();
#endif
  context = Box<Context>::make(this);

  instance.bind(this);
}

Window::~Window()
{
  instance.reset();
}

Ref<Context> Window::getContext()
{
  return context;
}

Ref<SysWindow> Window::getSys()
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

  onDisplay();
}

void Window::onTick() { }
void Window::onDisplay() { }
void Window::onKeyboard() { }
void Window::onMouse() { }

}

