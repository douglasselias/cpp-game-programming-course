#pragma once

#include <vector>

#include "entity.hpp"

class EntityManager
{
  EntityVec entities;
  EntityVec entitiesToAdd;
  EntityMap entityMap;
  size_t totalEntities = 0;

  void removeDeadEntities(EntityVec &vec);

public:
  EntityManager();

  void update();
  std::shared_ptr<Entity> addEntity(const std::string &tag);

  const EntityVec &getEntities();
  const EntityVec &getEntities(const std::string &tag);
};

typedef std::vector<Entity> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;
