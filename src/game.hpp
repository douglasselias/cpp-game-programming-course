#pragma once

#include <SFML/Graphics.hpp>

#include "entity.hpp"
#include "entity_manager.hpp"

class Game {
  sf::RenderWindow window;
  EntityManager entities;
sf::Font font;
sf:Text text;
int score =0;
int currentFrame =0;
int lastEnemySpawnTime= 0;
bool paused =false;
bool running = true;

std::shared_ptr<Entity>player;

void init(const std:: string& config);
void setPaused(bool paused);

void movement();
void userInput();
void lifespan();
void render();
void enemySpawner();
void collision();

public:
void spawnPlayer();
void spawnEnemy();

void run();
};