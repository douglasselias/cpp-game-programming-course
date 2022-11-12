#include <memory>

#include "entity.hpp"
#include "entity_manager.hpp"

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag)
{
  auto entity = std::shared_ptr<Entity>(new Entity(totalEntities++, tag));
}

void EntityManager::update()
{
  for (auto e : entitiesToAdd)
  {
    entities.push_back(e);
  }

  entitiesToAdd.clear();

  // for (auto &[tag, entityVec] : entityMap)
  // {
  //   removeDeadEntities(entityVec);
  // }
}