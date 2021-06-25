#ifndef REND_MATHUTIL_H
#define REND_MATHUTIL_H

#include <iron>

namespace rend
{

struct Vec2
{
  Value<float> x;
  Value<float> y;

  Vec2() { }
  Vec2(float _x, float _y) : x(_x), y(_y) { }
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

struct Color
{
  Value<float> r;
  Value<float> g;
  Value<float> b;
  Value<float> a;

  Color() { }
  Color(float _r, float _g, float _b) : r(_r), g(_g), b(_b), a(0) { }
  Color(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a) { }
};

}

#endif

