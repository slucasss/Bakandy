#include "ColisionManager.h"



ColisionManager* ColisionManager::Instance = nullptr;


ColisionManager* ColisionManager::Get() {
	if (Instance == nullptr) {
		Instance = new ColisionManager;
	}
	return Instance;
}

bool ColisionManager::IsColiding(Geometry* e1, Geometry* e2) {
	Vector2f pos1 = e1->GetPosition(0, 0);
	Vector2f pos2 = e2->GetPosition(0, 0);



	SDL_Rect rect1 = { pos1.x, pos1.y, e1->GetWidth(), e1->GetHeight() };
	SDL_Rect rect2 = { pos2.x, pos2.y, e2->GetWidth(), e2->GetHeight() };

	return SDL_HasIntersection(&rect1, &rect2);
}

void ColisionManager::ColisionEnemyProjectiles(std::vector<Projectile*>* projectiles, std::vector<Enemy*>* enemies){
	for (int i = enemies->size() - 1; i >= 0; i--) {
		for (int a = projectiles->size() - 1; a >= 0; a--) {
			Projectile* projectile = (*projectiles)[a];
			Enemy* enemy = (*enemies)[i];
			if (IsColiding(projectile, enemy)){
				enemy->takeDamage(projectile->GetDgt());
		
				projectiles->erase(projectiles->begin() + a);
				delete projectile;
			}
		}
	}
}

bool ColisionManager::ColisionPlayerProjectiles(std::vector<Projectile*>* projectiles, Player* player) {
	for (int a = projectiles->size() - 1; a >= 0; a--) {
		Projectile* projectile = (*projectiles)[a];
		if (IsColiding(projectile, player)) {
			player->HaveDamage(projectile->GetDgt());
			
			projectiles->erase(projectiles->begin() + a);
			delete projectile;

			if (player->IsAlive() == false) {
				return false;
			}
		}
	}
}

void ColisionManager::ColisionPlayerEnemies(std::vector<Enemy*>* enemies, Player* player) {
	for (int a = enemies->size() - 1; a >= 0; a--) {
		Enemy* e = (*enemies)[a];
		if (IsColiding(e, player)) {
			player->HaveDamage(1);
		}
	}
}

void ColisionManager::ColisionPlayerObstacles(std::vector<Enemy*>* obstacles, Player* player) {
	for (int a = obstacles->size() - 1; a >= 0; a--) {
		Enemy* o = (*obstacles)[a];
		if (IsColiding(o, player)) {
			player->HaveDamage(2);
		}
	}
}



void ColisionManager::AllColision() {
	ColisionEnemyProjectiles(ProjectileManager::Get()->GetProjectilesPlayer(), EnemyManager::Get()->GetEnemies());
	ColisionEnemyProjectiles(ProjectileManager::Get()->GetProjectilesPlayer(), ObstacleManager::Get()->GetObstacles());
	ColisionPlayerProjectiles(ProjectileManager::Get()->GetProjectilesEnemies(), PlayerManager::Get()->GetPlayer());
	ColisionPlayerEnemies(EnemyManager::Get()->GetEnemies(), PlayerManager::Get()->GetPlayer());
	ColisionPlayerObstacles(ObstacleManager::Get()->GetObstacles(), PlayerManager::Get()->GetPlayer());
}