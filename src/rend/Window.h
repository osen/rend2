#include "sys.h"

#include <SDL2/SDL.h>

#include <iron>

namespace rend
{

struct Window : enable_ref
{
  static ref<Window> getInstance();

  Window();
  ~Window();

  void start();
  void stop();
  ref<SysContext> getContext();

private:
  static ref<Window> instance;

  box<SysSdl> sdl;
  box<SysWindow> window;
  box<SysContext> context;
  unique<bool> quit;

  virtual void onTick();
  virtual void onDisplay();
  virtual void onKeyboard();
  virtual void onMouse();

};

}
