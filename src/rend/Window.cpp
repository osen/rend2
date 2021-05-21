#include "Window.h"

namespace rend
{

box<Window> Window::instance;

ref<SDL_GLContext> Window::getContext()
{
  Window::show();

  return instance->context;
}

void Window::show()
{
  if(instance.valid())
  {
    //panic("Only one window instance allowed");
    return;
  }

  instance = box<Window>::make();
}

void Window::close()
{
  instance.reset();
}

Window::Window()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  window = box<SDL_Window *>::make();

  *window = SDL_CreateWindow("Rend",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    800, 600,
    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

  if(!*window)
  {
    panic("Failed to create window");
  }

  context = box<SDL_GLContext>::make();
  *context = SDL_GL_CreateContext(*window);

  if(!*context)
  {
    panic("Failed to create OpenGL context");
  }
}

Window::~Window()
{
  SDL_GL_DeleteContext(*context);
  SDL_DestroyWindow(*window);
  SDL_Quit();
}

}

