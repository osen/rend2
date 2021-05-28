#include <rend/rend.h>

struct SampleWindow : Window
{
  Image image;

  void onTick()
  {

  }
};

int main()
{
  SampleWindow window;

/*
  KeyInfo ki = Keyboard::queryKey(KEY_D);
 */

  window.start();

  return 0;
}
