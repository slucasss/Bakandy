#pragma once
#include "Character.h"
#include "ProjectileManager.h"


class Enemy : public Character
{
public:

	Enemy(int x, int y, int height, int width, int Hp, int baseAtk, int sp);

	virtual Projectile* attack() override = 0;

	virtual void MoveC(float deltaTime) override = 0;

	virtual void Draw(SDL_Renderer*) override = 0;


};

