#pragma once
#include <SDL.h>

#include"Player.h"
#include "Enemy.h"
#include "AssetManager.h"

class Obstacle1 : public Enemy
{
private:
public:
	Obstacle1(int x, int y);

	Projectile* attack() override;

	void MoveC(float deltaTime) override;

	void Draw(SDL_Renderer*) override;

};

