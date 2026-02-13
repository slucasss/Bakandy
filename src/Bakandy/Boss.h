#pragma once
#include <SDL.h>

#include"Player.h"
#include "Enemy.h"
#include "AssetManager.h"
#include "EnemyManager.h"
#include "Enemie3.h"
#include "Enemie1.h"

class Boss: public Enemy
{
private:
	Player* m_p;

	uint32_t timerAttack;
	uint32_t timer;
	int AttackState;
	int random;

public:
	Boss(int x, int y, Player* p);

	Projectile* attack() override;

	void MoveC(float deltaTime) override;

	void Draw(SDL_Renderer*) override;

};

