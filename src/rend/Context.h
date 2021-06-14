#include <iron>

namespace rend
{

struct SysContext;
struct Window;
struct Mesh;
struct Image;
struct UiShader;
struct BasicShader;
struct LightShader;

struct Context : enable_ref
{
  Context(ref<Window> window);

  ref<SysContext> getSys();
  box<Mesh> createMesh();
  box<Image> createImage();
  ref<UiShader> getUiShader();
  ref<BasicShader> getBasicShader();
  ref<LightShader> getLightShader();

private:
  box<SysContext> sys;
  box<UiShader> uiShader;

};

}

