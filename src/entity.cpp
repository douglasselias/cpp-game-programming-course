#include <iostream>
#include <memory>

#include "entity.hpp"

// Entity::Entity(const size_t id, const std::string &tag)
//     : id(id), tag(tag) {}

bool Entity::isActive() const
{
  return active;
}

const std::string &Entity::tag() const
{
  return tag();
}

const size_t Entity::id() const
{
  return id();
}

void Entity::destroy()
{
  active = false;
}
