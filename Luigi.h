#pragma once
#include "Character.h"

class Luigi : public Character{
    public:
        Luigi();
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