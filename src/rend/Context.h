#include <iron>

namespace rend
{

struct SysContext;
struct Window;
struct Mesh;
struct Image;

struct Context : enable_ref
{
  Context(ref<Window> window);

  ref<SysContext> getSys();
  box<Mesh> createMesh();
  box<Image> createImage();

private:
  box<SysContext> sys;

};

}

