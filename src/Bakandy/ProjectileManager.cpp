#include "ProjectileManager.h"


ProjectileManager* ProjectileManager::Instance = nullptr;


ProjectileManager* ProjectileManager::Get() {
	if (Instance == nullptr) {
		Instance = new ProjectileManager;
	}
	return Instance;
}



void ProjectileManager::DrawAllProjectiles(SDL_Renderer* renderer) {
	for (auto proj : projectilesEnemies) {
		proj->Draw(renderer);
	}
	for (auto proj : projectilesPlayer) {
		proj->Draw(renderer);
	}
}


void ProjectileManager::MoveProjectiles(float deltaTime) {

	for (int i = projectilesEnemies.size() - 1; i >= 0; i--)
	{
		if (projectilesEnemies[i]->MoveP(deltaTime) == false) {
			delete (projectilesEnemies[i]);
			projectilesEnemies.erase(projectilesEnemies.begin() + i);
		}
	}
	for (int i = projectilesPlayer.size() - 1; i >= 0; i--)
	{
		if (projectilesPlayer[i]->MoveP(deltaTime) == false) {
			delete (projectilesPlayer[i]);
			projectilesPlayer.erase(projectilesPlayer.begin() + i);
		}
	}
}

void ProjectileManager::Clear() {
	for (int i = projectilesEnemies.size() - 1; i >= 0; i--) {
		Projectile* p = projectilesEnemies[i];
		projectilesEnemies.erase(projectilesEnemies.begin() + i);
		delete(p);
	}
	for (int i = projectilesPlayer.size() - 1; i >= 0; i--) {
		Projectile* p = projectilesPlayer[i];
		projectilesPlayer.erase(projectilesPlayer.begin() + i);
		delete(p);
	}
}