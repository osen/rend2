#include <iron>

namespace rend
{

struct SysContext;
struct Window;
struct Mesh;

struct Context : enable_ref
{
  Context(ref<Window> window);

  ref<SysContext> getSys();
  box<Mesh> createMesh();

private:
  box<SysContext> sys;

};

}

