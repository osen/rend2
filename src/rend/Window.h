#include <SDL2/SDL.h>

#include <iron>

namespace rend
{

struct Window
{
  static ref<Window *> getInstance();

  Window();
  ~Window();

  void start();
  void stop();
  ref<SDL_GLContext> getContext();

private:
  static ref<Window *> instance;

  unique<Window *> self;
  unique<SDL_Window *> window;
  unique<SDL_GLContext> context;
  unique<bool> quit;

  virtual void onTick();
  virtual void onDisplay();
  virtual void onKeyboard();
  virtual void onMouse();

};

}
