#include <iron>

#include <GL/glew.h>

namespace rend
{

struct SysContext;
struct Window;
struct Mesh;
struct Texture;
struct UiShader;
struct BasicShader;
struct LightShader;

struct Context : EnableRef, DisableCopy
{
  Context(Ref<Window> window);

  Ref<SysContext> getSys();
  Box<Mesh> createMesh();
  Box<Texture> createTexture();
  Ref<UiShader> getUiShader();
  Ref<BasicShader> getBasicShader();
  Ref<LightShader> getLightShader();

  static GLuint getId(Texture const& texture);

private:
  Box<SysContext> sys;
  Box<UiShader> uiShader;

};

}

