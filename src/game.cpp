#include "game.hpp"

void Game::run()
{
  while (running)
  {
    entities.update();

    if (!paused)
    {
      enemySpawner();
      movement();
      collision();
      userInput();
    }

    render();
    currentFrame++;
  }
};

void Game::spawnPlayer()
{
  auto entity = entities.addEntity("player");
  entity->transform = std::make_shared<Transform>(Vec2(0, 0), Vec2(0, 0), 0);
  entity->input = std::make_shared<Input>();

  player = entity;
};

void Game::render()
{
  window.clear();

  window.draw(player->shape->circle);

  window.display();
}

void Game::userInput()
{
  sf::Event event;

  while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      running = false;
    }

    if (event.type == sf::Event::KeyPressed)
    {
      switch (event.key.code)
      {
      case sf::Keyboard::W:
        player->input->up = true;
        break;
      default:
        break;
      }
    }

    if (event.type == sf::Event::KeyReleased)
    {
      switch (event.key.code)
      {
      case sf::Keyboard::W:
        player->input->up = false;
        break;
      default:
        break;
      }
    }
  }
}

void Game::movement()
{
  player->transform->velocity.x = 0;
  player->transform->velocity.y = 0;

  if (player->input->up)
  {
    player->transform->velocity.y = -5;
  }

  player->transform->position += player->transform->velocity;
}