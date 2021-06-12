#ifndef REND_MATHUTIL_H
#define REND_MATHUTIL_H

#include <iron>

namespace rend
{

struct Vec2
{
  val<float> x;
  val<float> y;
};

struct Vec3
{
  val<float> x;
  val<float> y;
  val<float> z;
};

struct Vec4
{
  val<float> x;
  val<float> y;
  val<float> z;
  val<float> w;

  Vec4();
  Vec4(Vec3 const &xyz, float w);
  Vec4(Vec2 const &xy, float z, float w);
  Vec4(float x, float y, float z, float w);

  Vec4 operator+(Vec4 const &value) const;
  Vec4 operator-(Vec4 const &value) const;
  Vec4 operator*(Vec4 const &value) const;
  Vec4 operator/(Vec4 const &value) const;
  Vec4 operator*(float value) const;
  Vec4 operator/(float value) const;
};

struct Mat4
{
  static Mat4 identity();
  static Mat4 perspective(float fov, float aspect, float near, float far);
  static Mat4 orthographic(float width, float height);

  array<float, 16> m;

  Vec4 operator*(Vec4 const &value) const;
};

struct Rect
{
  val<float> x;
  val<float> y;
  val<float> width;
  val<float> height;
};

}

#endif

