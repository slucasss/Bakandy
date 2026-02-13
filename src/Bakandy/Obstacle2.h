#pragma once
#include <SDL.h>

#include"Player.h"
#include "Enemy.h"
#include "AssetManager.h"

class Obstacle2 : public Enemy
{
private:
public:
	Obstacle2(int x, int y);

	Projectile* attack() override;

	void MoveC(float deltaTime) override;

	void Draw(SDL_Renderer*) override;

};

