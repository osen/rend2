#include "Image.h"
#include "Context.h"
#include "sys.h"

namespace rend
{

Image::Image(Ref<Context> context) : context(context)
{
  //sys = Box<SysTexture>::make(context->getSys());
}

}

