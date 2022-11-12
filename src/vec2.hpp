#pragma once

class Vec2
{
public:
  float x = 0;
  float y = 0;

  Vec2();
  Vec2(float x, float y);

  bool operator==(const Vec2 &rhs) const;
  bool operator!=(const Vec2 &rhs) const;

  Vec2 operator+(const Vec2 &rhs) const;
  Vec2 operator-(const Vec2 &rhs) const;
  Vec2 operator/(const float value) const;
  Vec2 operator*(const float value) const;

  void operator+=(const Vec2 &rhs);
  void operator-=(const Vec2 &rhs);
  void operator/=(const float value);
  void operator*=(const float value);

  float distance(const Vec2 &rhs) const;

  float length() const;
  void normalize();

  Vec2& add(const Vec2& v);
};