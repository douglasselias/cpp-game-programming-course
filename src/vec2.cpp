#include <math.h>

class Vec2
{

public:
  float x = 0;
  float y = 0;

  Vec2() {}

  Vec2(float x, float y)
      : x(x), y(y) {}

  Vec2 operator+(const Vec2 &rhs) const
  {
    return Vec2(x + rhs.x, y + rhs.y);
  }

  void operator+=(const Vec2 &rhs)
  {
    x += rhs.x;
    y += rhs.y;
  }

  Vec2 &add(const Vec2 &v)
  {
    x += v.x;
    y += v.y;
    return *this;
  }

  float dist(const Vec2 &v) const
  {
    return sqrtf((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y));
  }
};