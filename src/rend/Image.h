#include <iron>

namespace rend
{

struct SysTexture;

struct Image
{
  Image();
  ~Image();

private:
  box<SysTexture> sys;

};

}
