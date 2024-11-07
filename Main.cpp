#include <SFML/Graphics.hpp>
#include <vector>
#include "Character.h"
#include "Mario.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
    sf::Clock gclock;
    std::vector<Character*> characters;

    characters.push_back(new Mario());
    map.CreateDummyMap(30);

    gclock.restart();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (Character* character : characters){
            character->Update(gclock.getElapsedTime().asSeconds());
            gclock.restart();
        }
        window.clear(sf::Color(135,206,235));
        map.Draw(window);
        for (Character* character : characters){
            character->Draw(window);
        }
        window.display();
    }

    return 0;
}
