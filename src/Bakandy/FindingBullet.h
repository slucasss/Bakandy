#pragma once
#include <SDL.h>
#include <vector>
#include <cmath>

#include "Projectile.h"
#include "EnemyManager.h"
#include "AssetManager.h"

class FindingBullet : public Projectile
{




public:
	FindingBullet(int x, int y, int mx, int my);

	bool MoveP(float deltaTime) override;

	void Draw(SDL_Renderer* rendererer);



};

