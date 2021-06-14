#ifndef REND_SHADER_H
#define REND_SHADER_H

#include <iron>

namespace rend
{

struct Context;
struct SysProgram;

struct Shader
{
  Shader(ref<Context> context);

protected:
  box<SysProgram> sys;
};

}

#endif

