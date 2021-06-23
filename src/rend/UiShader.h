#include "Shader.h"

#include <iron>

namespace rend
{

struct Context;

struct UiShader : Shader
{
  UiShader(Ref<Context> context);
};

}

