#include "EnemyManager.h"
#include "Boss.h"

EnemyManager* EnemyManager::Instance = nullptr;

EnemyManager* EnemyManager::Get() {
	if (Instance == nullptr) {
		Instance = new EnemyManager;
	}
	return Instance;
}

void EnemyManager::AddEnemy(Enemy* e) {
	if (e != nullptr) {
		enemies.push_back(e);
	}
}

void EnemyManager::DrawEnemies(SDL_Renderer* renderer) {
	for (auto e : enemies) {
		e->Draw(renderer);
	}
}

void EnemyManager::MoveEnemies(float deltaTime) {
	for (int i = enemies.size() - 1; i >= 0; i--) {
		Enemy* e = enemies[i];
		e->MoveC(deltaTime);

		Vector2f pos = e->GetPosition();
		if (pos.x < -100) {
			enemies.erase(enemies.begin() + i);
			delete(e);
		}
		else if (pos.y < -50) {
			enemies.erase(enemies.begin() + i);
			delete(e);
		}
		else if (pos.y > 650) {
			enemies.erase(enemies.begin() + i);
			delete(e);
		}
	}
}

void EnemyManager::AttackEnemies() {
	for (auto e : enemies) {
		e->attack();
	}
}

bool EnemyManager::Death() {
	for (int i = enemies.size() - 1; i >= 0; i--) {
		Enemy* e = enemies[i];
		if (!e->IsAlive()){
			if (typeid(*e) == typeid(Boss)) {
				return true;
			}
			enemies.erase(enemies.begin() + i);
			delete(e);
		}
	}
	return false;
}

void EnemyManager::Clear() {
	for (int i = enemies.size() - 1; i >= 0; i--) {
		Enemy* e = enemies[i];
		enemies.erase(enemies.begin() + i);
		delete(e);
	}
}