#ifndef REND_MATHUTIL_H
#define REND_MATHUTIL_H

#include <iron>

namespace rend
{

struct Vec2
{
  Value<float> x;
  Value<float> y;
};

struct Vec3
{
  Value<float> x;
  Value<float> y;
  Value<float> z;
};

struct Vec4
{
  Value<float> x;
  Value<float> y;
  Value<float> z;
  Value<float> w;

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

  Array<float, 16> m;

  Vec4 operator*(Vec4 const &value) const;
};

struct Rect
{
  Value<float> x;
  Value<float> y;
  Value<float> width;
  Value<float> height;
};

}

#endif

