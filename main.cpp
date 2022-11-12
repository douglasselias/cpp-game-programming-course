#include <functional>
#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "src/vec2.cpp"

const uint screenWidth = 1080;
const uint screenHeight = 720;
const std::string gameName = "My Game";

int main()
{
  sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), gameName);
  window.setFramerateLimit(60);

  sf::Font font;
  if (!font.loadFromFile("src/fonts/RussoOne.ttf"))
  {
    std::cerr << "Could not load font!\n";
    exit(-1);
  }

  sf::Text text("Sphinx of Black Quartz, Judge My Vow", font, 24);
  text.setFillColor(sf::Color::White);
  text.setPosition(0, screenHeight - text.getCharacterSize() - 10);

  std::shared_ptr<sf::Shape> circlePtr = std::make_shared<sf::CircleShape>(10);

  std::shared_ptr<sf::Drawable> textPtr = std::make_shared<sf::Text>("Sphinx of Black Quartz, Judge My Vow", font, 24);
  std::static_pointer_cast<sf::Text>(textPtr)->setFillColor(sf::Color::White);
  std::static_pointer_cast<sf::Text>(textPtr)->setPosition(0, screenHeight - std::static_pointer_cast<sf::Text>(textPtr)->getCharacterSize() - 10);

  std::vector<std::shared_ptr<sf::Drawable>> drawables;

  drawables.push_back(circlePtr);
  drawables.push_back(textPtr);

  Vec2 v(1, 2);
  Vec2 v1(2, 3);
  Vec2 vr = v + v1;

  std::cout << vr.x << "\n";

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Black);

    window.draw(text);

    for (auto &d : drawables)
    {
      window.draw(*d);
    }

    window.display();
  }

  return 0;
}
