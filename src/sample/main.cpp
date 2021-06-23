#include <rend/rend.h>

struct SampleWindow : rend::Window
{
  Box<Image> image;

  SampleWindow()
  {
    image = getContext()->createImage();
  }

  void onTick()
  {

  }

  void onDisplay()
  {
    Ref<UiShader> ui = getContext()->getUiShader();
  }
};

int main()
{
  SampleWindow window;
  Ref<Context> context(window.getContext());

  Value<Vector<int> > ints;
  ints->push(8);
  Ref<Vector<int> > refInts = ints;

/*
  KeyInfo ki = Keyboard::queryKey(KEY_D);
 */

  Box<Mesh> m = context->createMesh();
  //Value<Face> f;
  //m->addFace(f);

  window.start();

  return 0;
}

