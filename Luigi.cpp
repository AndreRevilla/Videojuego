#include "Luigi.h"
#include "Global.h"
#include <iostream>

Luigi::Luigi() {
    speed = 350;
    verticalVelocity = 0;
    gravity = 0.1f;

    rect = sf::FloatRect(100, 50, 100, 100);
    if (!texture.loadFromFile("luigi.png")) {
        std::cerr << "Error al cargar luigi.png" << std::endl;
    }
    sprite = sf::Sprite(texture);
}

void Luigi::Update(float deltaTime){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        rect.left -= speed * deltaTime;
        facingLeft = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        rect.left += speed * deltaTime;
        facingLeft = false;
    }

    Mario::Update(deltaTime);

}

// Sobrescribe el método Draw si deseas cambiar la apariencia
void Luigi::Draw(sf::RenderWindow& window){
    sprite.setPosition(rect.left, rect.top);
    sprite.setScale(rect.width / texture.getSize().x, rect.height / texture.getSize().y);
    sprite.setTextureRect(sf::IntRect(texture.getSize().x * (facingLeft ? 1 : 0), 0,
        texture.getSize().x * (facingLeft ? -1 : 1), texture.getSize().y));
    window.draw(sprite);
}

void Luigi::Jump(){
    verticalVelocity = -5.0f; // Luigi va a saltar más alto
}
