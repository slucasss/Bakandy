#include "PlayerManager.h"
#include "FindingBullet.h"


PlayerManager* PlayerManager::Instance = nullptr;
Player* PlayerManager::player = nullptr;

PlayerManager::PlayerManager() {
	player = new Player(150, 300);
	LastTimeShotMissile = 0;
}

PlayerManager* PlayerManager::Get() {
	if (Instance == nullptr) {
		Instance = new PlayerManager;
	}
	return Instance;
}

void PlayerManager::Move(float deltaTime) {
	Vector2f pos = player->GetPosition();

	if (InputManager::Get()->IsHeld(SDLK_z)) {
		player->moving = true;
		if (pos.y > 20) {
			player->Move(0, -player->GetSpeed() * deltaTime);
		}
		else {
			player->SetPosition(pos.x, 570);
		}
	}

	if (InputManager::Get()->IsHeld(SDLK_s)) {
		player->moving = true;
		if (pos.y < 580) {
			player->Move(0, player->GetSpeed() * deltaTime);
		}
		else {
			player->SetPosition(pos.x, 30);
		}
	}

	if (InputManager::Get()->IsHeld(SDLK_q)) {
		player->moving = true;
		if (pos.x > 30) {
			player->Move(-player->GetSpeed() * deltaTime, 0);
		}
	}

	if (InputManager::Get()->IsHeld(SDLK_d)) {
		player->moving = true;
		if (pos.x < 400) {
			player->Move(player->GetSpeed() * deltaTime, 0);
		}
	}
	else {
		player->moving = false;
	}

}

void PlayerManager::Attack() {
	if (InputManager::Get()->IsDown(SDLK_SPACE))
	{
		Projectile* proj = player->attack();
		if (proj != nullptr) {
			ProjectileManager::Get()->AddProjectilePlayer(proj);
		}
	}
	else if (InputManager::Get()->IsDown(SDLK_e))
	{
		Uint32 currentTime = SDL_GetTicks();
		
		if ((currentTime - LastTimeShotMissile ) > 5000) {
			LastTimeShotMissile = currentTime;
			Vector2f pos = player->GetPosition(0.9, 0.5);
			FindingBullet* proj = new FindingBullet(pos.x, pos.y, 300, 0);

			if (proj != nullptr) {
				ProjectileManager::Get()->AddProjectilePlayer(proj);
			}
		}
	}
}

void PlayerManager::Clear() {
	delete(player);
	player = new Player(150, 300);
	LastTimeShotMissile = 0;
}