
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include "SpeedBoostAbility.h"
#include "Game.h"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Test");
    window.setFramerateLimit(60);
    
    Game game = Game();
    
    sf::RenderTexture texture;
    if (!texture.create(1600, 1200)) {
        //QQ
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Right) {
                std::cout << "Right click\n";
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;
                game.setChampionTarget(*new sf::Vector2f(x, y));
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                game.castChampionAbility(sf::Vector2f(localPosition.x, localPosition.y));
            }
        }
        
        game.update();
        window.clear(sf::Color::White);
        sf::Sprite sprite;
        game.draw(texture);
        sprite.setTexture(texture.getTexture());
        
        // draw everything here...
        window.draw(sprite);
        window.display();
    }

    return EXIT_SUCCESS;
}
