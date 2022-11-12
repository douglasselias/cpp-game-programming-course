#pragma once

#include "components.hpp"

#include <memory>
#include <string>

class Entity
{
  friend class EntityManager;

  bool active = true;
  const size_t id = 0;
  const std::string tag = "default";

  Entity(const size_t id, const std::string &tag);

public:
  std::shared_ptr<Transform> transform;
  std::shared_ptr<Shape> shape;
  std::shared_ptr<Collision> collision;
  std::shared_ptr<Input> input;
  std::shared_ptr<Score> score;
  std::shared_ptr<Lifespan> lifespan;

  bool isActive() const;
  const std::string &tag() const;
  const size_t id() const;
  void destroy();
};