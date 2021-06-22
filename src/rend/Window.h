#include "sys.h"

//#include <iron>

namespace rend
{

struct Context;
struct SysWindow;

struct Window :
#ifdef USE_FLTK
SysWindow
#else
enable_ref
#endif
{
  //static ref<Window> getInstance();

  Window();
  ~Window();

  void start();
  void stop();
  ref<Context> getContext();
  ref<SysWindow> getSys();

private:
  static ref<Window> instance;

#ifdef USE_SDL2
  box<SysWindow> sys;
#endif

  ::box<Context> context;
  unique<bool> quit;
  unique<bool> initialized;

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
