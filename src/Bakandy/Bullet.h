#pragma once
#include <SDL.h>

#include "Projectile.h"
#include "AssetManager.h"

class Bullet : public Projectile
{


public:
	Bullet(int x, int y, int mx, int my);

	bool MoveP(float deltaTime) override;

	void Draw(SDL_Renderer* rendererer);



};

