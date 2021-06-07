#include "Image.h"
#include "Context.h"
#include "sys.h"

namespace rend
{

Image::Image(ref<Context> context) : context(context)
{
  sys = box<SysTexture>::make(context->getSys());
}

}

