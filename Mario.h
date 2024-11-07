#pragma once
#include "Character.h"

class Mario : public Character{
    public:
        Mario();
        void Update(float deltaTime) override;
        void Draw(sf::RenderWindow& window) override;
    private:
        float speed;
        float verticalVelocity;
        float gravity;
        bool facingLeft;
        sf::Texture texture;
        sf::Sprite sprite;
};