#pragma once
#include "Player.h"
#include "InputManager.h"
#include "ProjectileManager.h"
#include "Projectile.h"

class PlayerManager
{
private:

	static PlayerManager* Instance;
	static Player* player;

	uint32_t LastTimeShotMissile;

	PlayerManager();

public:

	static PlayerManager* Get();

	void Move(float deltaTime);

	void Attack();

	Player* GetPlayer() { return player; }

	void Clear();
};

