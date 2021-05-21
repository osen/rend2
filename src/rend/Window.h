#include <SDL2/SDL.h>

#include <iron>

namespace rend
{

struct Window
{
  Window();
  ~Window();

  static void show();
  static void close();
  static ref<SDL_GLContext> getContext();

private:
  static box<Window> instance;

  box<SDL_Window *> window;
  box<SDL_GLContext> context;
};

}
