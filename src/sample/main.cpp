#include <rend/rend.h>
#include <FL/Fl_Gl_Window.H>

struct MainWindow : Fl_Gl_Window
{
  rend::Texture texture;

  MainWindow() : Fl_Gl_Window(800, 600)
  {
    resizable(this);
    texture.load("assets/logo.png");
  }

  void draw()
  {
    rend::clear(rend::Color(1, 0, 1));

    rend::draw(texture, rend::Vec2(10, 10));
  }
};

int main()
{
  MainWindow mw;
  mw.show();

  Fl::run();

  return 0;
}

