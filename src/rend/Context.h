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

struct Context : EnableRef
{
  Context(Ref<Window> window);

  Ref<SysContext> getSys();
  Box<Mesh> createMesh();
  Box<Image> createImage();
  Ref<UiShader> getUiShader();
  Ref<BasicShader> getBasicShader();
  Ref<LightShader> getLightShader();

private:
  Box<SysContext> sys;
  Box<UiShader> uiShader;

};

}

