#pragma once

#include <SFML/Graphics.hpp>

#include "vec2.hpp"

class Transform
{
public:
  Vec2 position = {0, 0};
  Vec2 velocity = {0, 0};
  float angle = 0;

  Transform(const Vec2 &position, const Vec2 &velocity, float angle)
      : position(position), velocity(velocity), angle(angle) {}
};

class Shape
{
public:
  sf::CircleShape circle;

  Shape(float radius, int points, const sf::Color &fill, const sf::Color &outline, float thickness) : circle(radius, points)
  {
    circle.setFillColor(fill);
    circle.setOutlineColor(outline);
    circle.setOutlineThickness(thickness);
    circle.setOrigin(radius, radius);
  }
};

class Collision
{
public:
  float radius = 0;
  Collision(float radius) : radius(radius) {}
};

class Score
{
public:
  int score = 0;

  Score(int score) : score(score) {}
};

class Lifespan
{
  public:
  int remaining=0;
  int total= 0;

  Lifespan(int total):remaining(total), total(total){}
};

class Input {
  public:
  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;
  bool shoot = false;

  Input(){}
};