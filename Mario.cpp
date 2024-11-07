#include "Mario.h"
#include "Global.h"
#include <iostream>

Mario::Mario() : speed(300), verticalVelocity(0), gravity(.1){
    rect = sf::FloatRect(50,50,100,100);
    texture.loadFromFile("mario.png");
    sprite = sf::Sprite(texture); 
}

void Mario::Update(float deltaTime){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        rect.left -= speed * deltaTime;
        facingLeft = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        rect.left += speed * deltaTime;
        facingLeft = false;
    }
    rect.top += verticalVelocity * deltaTime;
    verticalVelocity += gravity * deltaTime;

    if((rect.top + rect.height) > HEIGHT)
    rect.top = HEIGHT - rect.height;
}

void Mario::Draw(sf::RenderWindow& window){
    sprite.setPosition(rect.left, rect.top);
    sprite.setScale(rect.width / texture.getSize().x, rect.height / texture.getSize().y);
    sprite.setTextureRect(sf::IntRect(texture.getSize().x * (facingLeft ? 1 : 0), 0,
        texture.getSize().x * (facingLeft ? -1 : 1), texture.getSize().y));
    window.draw(sprite);
}