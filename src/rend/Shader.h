#ifndef REND_SHADER_H
#define REND_SHADER_H

#include <iron>

namespace rend
{

struct Context;
struct SysProgram;

struct Shader : DisableCopy
{
  Shader(Ref<Context> context);

protected:
  Box<SysProgram> sys;
};

}

#endif

