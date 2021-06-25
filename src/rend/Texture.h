#include <memory>
#include <string>

namespace rend
{

struct Color;
struct Context;
struct Texture
{
  Texture();
  void setSize(int _w, int _h);
  void setPixel(int _x, int _y, Color const& _color);
  void load(std::string const& _path);

private:
  friend struct Context;
  struct Impl;
  std::shared_ptr<Impl> m_impl;

};

}
