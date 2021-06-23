#include <iron>

namespace rend
{

struct SysTexture;
struct Context;

struct Image
{
  Image(Ref<Context> context);

private:
  friend struct Context;

  Box<SysTexture> sys;
  Ref<Context> context;

};

}
