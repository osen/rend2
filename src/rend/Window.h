#include "sys.h"

#include <SDL2/SDL.h>

#include <iron>

namespace rend
{

struct Context;

struct Window : enable_ref
{
  static ref<Window> getInstance();

  Window();
  ~Window();

  void start();
  void stop();
  ref<Context> getContext();
  ref<SysWindow> getSys();

private:
  static ref<Window> instance;

  box<SysSdl> sdl;
  box<SysWindow> sys;

  box<Context> context;
  unique<bool> quit;

  virtual void onTick();
  virtual void onDisplay();
  virtual void onKeyboard();
  virtual void onMouse();

};

}
