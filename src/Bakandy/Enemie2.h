#pragma once
#include <SDL.h>

#include"Player.h"
#include "Enemy.h"

class Enemie2 : public Enemy
{
private:
	Player* m_p;
public:
	Enemie2(int x, int y, Player* p);

	Projectile* attack() override;

	void MoveC(float deltaTime) override;

	void Draw(SDL_Renderer*) override;

};

