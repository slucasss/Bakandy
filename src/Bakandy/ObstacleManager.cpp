#include "ObstacleManager.h"

ObstacleManager* ObstacleManager::Instance = nullptr;

ObstacleManager* ObstacleManager::Get() {
	if (Instance == nullptr) {
		Instance = new ObstacleManager;
	}
	return Instance;
}

void ObstacleManager::AddObstacles(Enemy* o) {
	if (o != nullptr) {
		obstacles.push_back(o);
	}
}

void ObstacleManager::DrawObstacles(SDL_Renderer* renderer) {
	for (Enemy* o : obstacles) {
		o->Draw(renderer);
	}
}

void ObstacleManager::MoveObstacles(float deltaTime) {
	for (int i = obstacles.size() - 1; i >= 0; i--) {
		Enemy* o = obstacles[i];
		
		o->MoveC(deltaTime);


		Vector2f pos = o->GetPosition();
		if (pos.x < -100) {
			obstacles.erase(obstacles.begin() + i);
			delete(o);
		}
		else if (pos.y < -50) {
			obstacles.erase(obstacles.begin() + i);
			delete(o);
		}
		else if (pos.y > 650) {
			obstacles.erase(obstacles.begin() + i);
			delete(o);
		}

	}
	
}

void ObstacleManager::Death() {
	for (int i = obstacles.size() - 1; i >= 0; i--) {
		Enemy* o = obstacles[i];
		if (!o->IsAlive()) {
			obstacles.erase(obstacles.begin() + i);
			delete(o);
		}
	}
}