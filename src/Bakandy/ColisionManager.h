#pragma once
#include <SDL.h>
#include <vector>

#include "Projectile.h"
#include "EnemyManager.h"
#include "PlayerManager.h"
#include "ProjectileManager.h"
#include "ObstacleManager.h"


class ColisionManager
{
	static ColisionManager* Instance;

public:
	static ColisionManager* Get();

	bool IsColiding(Geometry* e1, Geometry* e2);

	void ColisionEnemyProjectiles(std::vector<Projectile*>* projectiles, std::vector<Enemy*>* enemies);

	bool ColisionPlayerProjectiles(std::vector<Projectile*>* projectiles, Player* player);

	void ColisionPlayerEnemies(std::vector<Enemy*>* enemies, Player* player);

	void ColisionPlayerObstacles(std::vector<Enemy*>* enemies, Player* player);

	void AllColision();

};