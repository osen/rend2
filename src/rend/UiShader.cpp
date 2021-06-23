#include "UiShader.h"
#include "Context.h"
#include "sys.h"

namespace rend
{

static const char *vertSource =
  "attribute vec2 a_Position;              \n"
  "void main()                             \n"
  "{                                       \n"
  "  gl_Position = vec4(a_Position, 0, 1); \n"
  "}                                       \n";

static const char *fragSource =
  "void main()                             \n"
  "{                                       \n"
  "  gl_FragColor = vec4(1, 0, 0, 1);      \n"
  "}                                       \n";

UiShader::UiShader(Ref<Context> context) : Shader(context)
{
  Box<SysShader> vertShader =
    Box<SysShader>::make(context->getSys(), false);

  glShaderSource(vertShader->sys, 1, &vertSource, NULL);
  glCompileShader(vertShader->sys);

  int success = 0;
  glGetShaderiv(vertShader->sys, GL_COMPILE_STATUS, &success);

  if(!success)
  {
    panic("Failed to compile vertex shader");
  }

  Box<SysShader> fragShader =
    Box<SysShader>::make(context->getSys(), true);

  glShaderSource(fragShader->sys, 1, &fragSource, NULL);
  glCompileShader(fragShader->sys);

  success = 0;
  glGetShaderiv(fragShader->sys, GL_COMPILE_STATUS, &success);

  if(!success)
  {
    panic("Failed to compile fragment shader");
  }

  glAttachShader(sys->sys, vertShader->sys);
  glAttachShader(sys->sys, fragShader->sys);
  glLinkProgram(sys->sys);

  success = 0;
  glGetProgramiv(sys->sys, GL_LINK_STATUS, &success);

  if(!success)
  {
    panic("Failed to link shader program");
  }

  glDetachShader(sys->sys, vertShader->sys);
  glDetachShader(sys->sys, fragShader->sys);
}

}
