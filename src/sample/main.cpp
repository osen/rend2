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

  box<Mesh> m = window.getContext()->createMesh();
  //val<Face> f;
  //m->addFace(f);

  window.start();

  return 0;
}
