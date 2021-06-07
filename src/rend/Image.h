#include <iron>

namespace rend
{

struct SysTexture;
struct Context;

struct Image
{
  Image(ref<Context> context);

private:
  friend struct Context;

  box<SysTexture> sys;
  ref<Context> context;

};

}
