#include "Map.h"
#include <iostream>

Map::Map(){
    texture.loadFromFile("block.png");
    sprite.setTexture(texture);
    sprite.setScale((double)CELL_SIZE / texture.getSize().x,
        (double)CELL_SIZE / texture.getSize().y);
}

void Map::CreateDummyMap(int length){
    for(int i=0; i<length; i++){
        Column c = Column();
        c[c.size() - 1] = true;
        map.push_back(c);
    }
}

void Map::Draw(sf::RenderWindow& window){
    int x=0;
    for(Column& column : map){
        int y=0;
        for(bool& draw : column){
            if(draw){
                sprite.setPosition(x * CELL_SIZE, y * CELL_SIZE);
                window.draw(sprite);
            }
            y++;
        }
        x++;
    }
}