#pragma once
#include "Character.h"
#include "AssetManager.h"


class Player : public Character {
private:
    uint32_t LastTimeHit;


public:
    bool moving;

    Player(int x, int y);

    Projectile* attack() override;

    void Draw(SDL_Renderer*) override;

    void MoveC(float deltaTime) override;

    void HaveDamage(int dmg);
};
