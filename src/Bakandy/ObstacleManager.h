#pragma once
#include <vector>

#include "Enemy.h"

class ObstacleManager{
private:
	static ObstacleManager* Instance;

	std::vector<Enemy*> obstacles;

public:
	static ObstacleManager* Get();

	void AddObstacles(Enemy* o);

	void DrawObstacles(SDL_Renderer* renderer);

	void MoveObstacles(float deltaTime);

	std::vector<Enemy*>* GetObstacles() { return &obstacles; }

	void Death();
};





