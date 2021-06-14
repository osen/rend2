#include <rend/rend.h>

struct SampleWindow : Window
{
  box<Image> image;

  SampleWindow()
  {
    //image = getContext()->createImage();
    getContext()->createImage();
  }

  void onTick()
  {

  }
};

int main()
{
  SampleWindow window;
  ref<Context> context(window.getContext());

  val<vec<int> > ints;
  ints->push(8);
  ref<vec<int> > refInts = ints;

/*
  KeyInfo ki = Keyboard::queryKey(KEY_D);
 */

  ref<UiShader> ui = window.getContext()->getUiShader();
  box<Mesh> m = window.getContext()->createMesh();
  //val<Face> f;
  //m->addFace(f);

  window.start();

  return 0;
}
