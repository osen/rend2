#include "mathutil.h"

namespace rend
{

Vec4::Vec4() { }
Vec4::Vec4(Vec3 const &xyz, float w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) { }
Vec4::Vec4(Vec2 const &xy, float z, float w) : x(xy.x), y(xy.y), z(z), w(w) { }
Vec4::Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }

Vec4 Vec4::operator+(Vec4 const &value) const
{
  Vec4 rtn = *this;

  rtn.x += value.x;
  rtn.y += value.y;
  rtn.z += value.z;
  rtn.w += value.w;

  return rtn;
}

Vec4 Vec4::operator-(Vec4 const &value) const
{
  Vec4 rtn = *this;

  rtn.x -= value.x;
  rtn.y -= value.y;
  rtn.z -= value.z;
  rtn.w -= value.w;

  return rtn;
}

Vec4 Vec4::operator*(Vec4 const &value) const
{
  Vec4 rtn = *this;

  rtn.x *= value.x;
  rtn.y *= value.y;
  rtn.z *= value.z;
  rtn.w *= value.w;

  return rtn;
}

Vec4 Vec4::operator/(Vec4 const &value) const
{
  Vec4 rtn = *this;

  rtn.x /= value.x;
  rtn.y /= value.y;
  rtn.z /= value.z;
  rtn.w /= value.w;

  return rtn;
}

Vec4 Vec4::operator*(float value) const
{
  Vec4 rtn = *this;

  rtn.x *= value;
  rtn.y *= value;
  rtn.z *= value;
  rtn.w *= value;

  return rtn;
}

Vec4 Vec4::operator/(float value) const
{
  Vec4 rtn = *this;

  rtn.x /= value;
  rtn.y /= value;
  rtn.z /= value;
  rtn.w /= value;

  return rtn;
}

}

