#include "Window.h"
#include "Context.h"
#include "sys.h"

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

  sys = box<SysWindow>::make();
  context = box<Context>::make(this);

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
  return sys;
}

void Window::start()
{
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

    glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    onDisplay();

    SDL_GL_SwapWindow(sys->sys);
  }
}

void Window::stop()
{
  quit = true;
}

void Window::onTick() { }
void Window::onDisplay() { }
void Window::onKeyboard() { }
void Window::onMouse() { }

}

