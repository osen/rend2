#include "Window.h"

namespace rend
{

ref<Window *> Window::instance;

ref<Window *> Window::getInstance()
{
  return instance;
}

Window::Window()
{
  if(instance.valid())
  {
    panic("Only one window instance allowed");
  }

  SDL_Init(SDL_INIT_EVERYTHING);

  window = SDL_CreateWindow("Rend",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    800, 600,
    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

  if(!window)
  {
    panic("Failed to create window");
  }

  context = SDL_GL_CreateContext(window);

  if(!context)
  {
    panic("Failed to create OpenGL context");
  }

  self = this;
  instance = self;
}

Window::~Window()
{
  instance.reset();
  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

ref<SDL_GLContext> Window::getContext()
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

