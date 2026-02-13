#pragma once
#include <vector>

#include "Enemy.h"

class EnemyManager
{
private:
	static EnemyManager* Instance;
	
	std::vector<Enemy*> enemies;

public:
	static EnemyManager* Get();

	void AddEnemy(Enemy* e);

	void DrawEnemies(SDL_Renderer* renderer);

	void MoveEnemies(float deltaTime);

	void AttackEnemies();

	std::vector<Enemy*>* GetEnemies() { return &enemies; }

	bool Death();

	void Clear();
};



