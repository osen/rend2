#include "Window.h"

namespace rend
{

ref<Window> Window::instance;

ref<Window> Window::getInstance()
{
  return instance;
}

Window::Window()
{
  if(instance.valid())
  {
    panic("Only one window instance allowed");
  }

  sdl = box<SysSdl>::make();
  window = box<SysWindow>::make(sdl);
  context = box<SysContext>::make(window);

  instance.bind(this);
}

Window::~Window()
{
  instance.reset();
}

ref<SysContext> Window::getContext()
{
  return context;
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
  }

  onTick();
  onDisplay();
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

