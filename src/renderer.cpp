#include <functional>
#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include <raylib.h>

#include <SDL2/SDL.h>

const uint screenWidth = 1080;
const uint screenHeight = 720;
const char *gameName = "My Game";

void SFML_GameLoop(std::function<void(void)> callback);
void RAYLIB_GameLoop(std::function<void(void)> callback);
void SDL_GameLoop(std::function<void(void)> callback);

void gameLoop(std::function<void(void)> callback)
{
#ifdef FLAG_SFML
  SFML_GameLoop(callback);
// #elifdef FLAG_RAYLIB
#else
  RAYLIB_GameLoop(callback);
// #else
//   SDL_GameLoop(callback);
#endif
}

void SFML_GameLoop(std::function<void(void)> callback)
{
  sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), gameName);
  window.setFramerateLimit(60);

  sf::Font font;
  if (!font.loadFromFile("src/fonts/RussoOne.ttf"))
  {
    // error...
    std::cerr << "Could not load font!\n";
    exit(-1);
  }

  sf::Text text("Sphinx of Black Quartz, Judge My Vow", font, 24);
  text.setFillColor(sf::Color::White);
  text.setPosition(0, screenHeight - text.getCharacterSize() - 10);
  // text.setStyle(sf::Text::Bold | sf::Text::Underlined);

  std::shared_ptr<sf::Shape> circlePtr = std::make_shared<sf::CircleShape>(10);
  sf::CircleShape circle(10);
  circle.setFillColor(sf::Color(100, 250, 50));
  std::vector<std::shared_ptr<sf::Shape>> shapes;
  shapes.push_back(circlePtr);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();

      callback();
    }

    window.clear(sf::Color::Black);

    window.draw(text);
    window.draw(circle);

    for (auto &s : shapes)
    {
      window.draw(*s);
    }

    window.display();
  }
}

void RAYLIB_GameLoop(std::function<void(void)> callback)
{
  InitWindow(screenWidth, screenHeight, gameName);
  SetTargetFPS(60);

  Font font = LoadFontEx("src/fonts/RussoOne.ttf", 32, 0, 250);

  while (!WindowShouldClose())
  {
    callback();

    BeginDrawing();

    ClearBackground(BLACK);
    // DrawText("Hello world!", 0, 0, 24, WHITE);

    DrawTextEx(font, "Sphinx of Black Quartz, Judge My Vow", (Vector2){0.0f, 0.0f}, font.baseSize, 2, WHITE);
    // DrawText("Using TTF font generated", 20, GetScreenHeight() - 30, 20, GRAY);

    EndDrawing();
  }

  UnloadFont(font);
  CloseWindow();
}

void SDL_GameLoop(std::function<void(void)> callback)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return;
  }

  SDL_Window *window = SDL_CreateWindow(gameName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
  if (window == NULL)
  {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return;
  }

  SDL_Surface *surface = SDL_GetWindowSurface(window);
  SDL_UpdateWindowSurface(window);

  // TTF_Font* font = NULL;

  SDL_Event e;
  bool quit = false;
  while (quit == false)
  {
    while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
        quit = true;
    }
  }

  SDL_FreeSurface(surface);
  surface = NULL;

  SDL_DestroyWindow(window);
  window = NULL;

  SDL_Quit();
}
