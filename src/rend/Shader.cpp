#include "Shader.h"
#include "Context.h"
#include "sys.h"

namespace rend
{

Shader::Shader(ref<Context> context)
{
  sys = box<SysProgram>::make(context->getSys());
}

}
