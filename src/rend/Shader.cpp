#include "Shader.h"
#include "Context.h"
#include "sys.h"

namespace rend
{

Shader::Shader(Ref<Context> context)
{
  sys = Box<SysProgram>::make(context->getSys());
}

}
