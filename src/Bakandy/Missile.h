#pragma once
#include <SDL.h>

#include "Projectile.h"
#include "AssetManager.h"

class Missile : public Projectile
{


public:
	Missile(int x, int y, int mx, int my);

	bool MoveP(float deltaTime) override;

	void Draw(SDL_Renderer* rendererer);



};

