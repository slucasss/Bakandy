#include "Enemie2.h"
#include "Bullet.h"


Enemie2::Enemie2(int x, int y, Player* p) : Enemy(x, y, 113, 53, 2, 4, 100), m_p(p) {

}

void Enemie2::MoveC(float deltaTime) {
	if (m_y <= 560) {
		Move(-m_speed * deltaTime, -20 * deltaTime);
	}
	
}

void Enemie2::Draw(SDL_Renderer* renderer) {

	SDL_Texture* texture = nullptr;
	if (m_speed != 0) {
		texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Spaceship2.png");
	}
	else {
		texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Spaceship2WithoutFire-removebg-preview.png");
	}
	SDL_Rect rectDest = { m_x, m_y, m_width,m_height };
	SDL_Rect rectSrc = { 500, 50, 470, 200 };

	SDL_RenderCopy(renderer, texture, &rectSrc, &rectDest);

}

Projectile* Enemie2::attack() {


	Vector2f posPlayer = (*m_p).GetPosition();
	Vector2f pos = GetPosition(0.1, 0.5);
	Uint32 current_time = SDL_GetTicks();

	if (current_time > last_shot_time + COOLDOWN_MS) {

		if (posPlayer.y > m_y - 100 && posPlayer.y < m_y + 100) {


			Bullet* bul1 = new Bullet(pos.x, pos.y, -300, -100);
			ProjectileManager::Get()->AddProjectileEnemies(bul1);

			Bullet* bul2 = new Bullet(pos.x, pos.y, -300, 0);
			ProjectileManager::Get()->AddProjectileEnemies(bul2);

			Bullet* bul3 = new Bullet(pos.x, pos.y, -300, 100);
			ProjectileManager::Get()->AddProjectileEnemies(bul3);


			last_shot_time = current_time;
			COOLDOWN_MS = 700 + (rand() % 300);
		}
	}

	return nullptr;
}