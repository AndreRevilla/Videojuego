#pragma once

#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include "Global.h"

typedef std::array<bool,HEIGHT / CELL_SIZE> Column;

class Map{
    public:
        Map();
        void CreateDummyMap(int length);
        void Draw(sf::RenderWindow& window);
    private:
        std::vector<Column> map;
        sf::Texture texture;
        sf::Sprite sprite;
};
