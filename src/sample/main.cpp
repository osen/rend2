#include <rend/rend.h>

struct SampleWindow : rend::Window
{
  iron::box<Image> image;

  SampleWindow()
  {
    image = getContext()->createImage();
  }

  void onTick()
  {

  }

  void onDisplay()
  {
    ref<UiShader> ui = getContext()->getUiShader();
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

  box<Mesh> m = context->createMesh();
  //val<Face> f;
  //m->addFace(f);

  window.start();

  return 0;
}

