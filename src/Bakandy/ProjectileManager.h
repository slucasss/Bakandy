#pragma once
#include <vector>
#include <SDL.h>

#include "Projectile.h"
#include "InputManager.h"


class ProjectileManager
{
private:
	static ProjectileManager* Instance;

	std::vector<Projectile*> projectilesPlayer;
	std::vector<Projectile*> projectilesEnemies;

public:

	static ProjectileManager* Get();

	void DrawAllProjectiles(SDL_Renderer* renderer);
	
	void MoveProjectiles(float deltaTime);

	std::vector<Projectile*>* GetProjectilesPlayer() { return &projectilesPlayer; }

	std::vector<Projectile*>* GetProjectilesEnemies() { return &projectilesEnemies; }

	void AddProjectilePlayer(Projectile* proj) { projectilesPlayer.push_back(proj); }

	void AddProjectileEnemies(Projectile* proj) { projectilesEnemies.push_back(proj); }

	void Clear();
};

