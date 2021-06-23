#include "sys.h"

//#include <iron>

namespace rend
{

struct Context;
struct SysWindow;

struct Window
#ifdef USE_FLTK
: SysWindow
#else
: EnableRef, DisableCopy
#endif
{
  //static Ref<Window> getInstance();

  Window();
  ~Window();

  void start();
  void stop();
  Ref<Context> getContext();
  Ref<SysWindow> getSys();

private:
  static Ref<Window> instance;

#ifdef USE_SDL2
  Box<SysWindow> sys;
#endif

  Box<Context> context;
  Value<bool> quit;
  Value<bool> initialized;

#ifdef USE_FLTK
  void draw();
#endif
  void display();

  virtual void onTick();
  virtual void onDisplay();
  virtual void onKeyboard();
  virtual void onMouse();

};

}
