#include <math.h>

#include "vec2.hpp"

Vec2::Vec2() {}

Vec2::Vec2(float x, float y)
    : x(x), y(y) {}

bool Vec2::operator==(const Vec2 &rhs) const
{
  return x == rhs.x && y == rhs.y;
}

bool Vec2::operator!=(const Vec2 &rhs) const
{
  return x != rhs.x || y != rhs.y;
}

Vec2 Vec2::operator+(const Vec2 &rhs) const
{
  return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 Vec2::operator-(const Vec2 &rhs) const
{
  return Vec2(x - rhs.x, y + rhs.y);
}

Vec2 Vec2::operator/(const float value) const
{
  return Vec2(x / value, y / value);
}

Vec2 Vec2::operator*(const float value) const
{
  return Vec2(x * value, y * value);
}

void Vec2::operator+=(const Vec2 &rhs)
{
  x += rhs.x;
  y += rhs.y;
}

void Vec2::operator-=(const Vec2 &rhs)
{
  x -= rhs.x;
  y -= rhs.y;
}

void Vec2::operator/=(const float value)
{
  x /= value;
  y /= value;
}

void Vec2::operator*=(const float value)
{
  x *= value;
  y *= value;
}

float Vec2::distance(const Vec2 &v) const
{
  return sqrtf((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y));
}

float Vec2::length() const
{
  return sqrtf((x * x) + (y * y));
}

void Vec2::normalize()
{
  x /= this->length();
  y /= this->length();
}

Vec2 &Vec2::add(const Vec2 &v)
{
  x += v.x;
  y += v.y;
  return *this;
}