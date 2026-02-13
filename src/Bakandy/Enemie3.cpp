#include "Enemie3.h"
#include "Bullet.h"


Enemie3::Enemie3(int x, int y, Player* p) : Enemy(x, y, 113, 53, 3, 10, 100), m_p(p) {

}




void Enemie3::MoveC(float deltaTime) {
	if (m_x > 900) {
		Move(-m_speed * deltaTime, 40 * deltaTime);

	}
	if (m_x > 700 && m_x < 900) {
		Move(-m_speed * deltaTime, -40 * deltaTime);

	}
	
	if (m_x > 500 && m_x < 700) {
		Move(-m_speed * deltaTime, 40 * deltaTime);

	}
	
	if (m_x > 300 && m_x < 500) {
		Move(-m_speed * deltaTime, -40 * deltaTime);

	}
	
	if (m_x > 100 && m_x < 300) {
		Move(-m_speed * deltaTime, 40 * deltaTime);

	}
	
	if (m_x < 100) {
		Move(-m_speed * deltaTime , -40 * deltaTime);

	}
}

void Enemie3::Draw(SDL_Renderer* renderer) {

	SDL_Texture* texture = nullptr;
	if (m_speed != 0) {
		texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Spaceship2.png");
	}
	else {
		texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Spaceship2WithoutFire-removebg-preview.png");
	}
	SDL_Rect rectDest = { m_x, m_y, m_width,m_height };
	SDL_Rect rectSrc = { 500, 295, 470, 200 };

	SDL_RenderCopy(renderer, texture, &rectSrc, &rectDest);

}

Projectile* Enemie3::attack() {


	Vector2f posPlayer = (*m_p).GetPosition();
	Vector2f pos = GetPosition(0.1, 0.5);
	Uint32 current_time = SDL_GetTicks();

	if (current_time > last_shot_time + COOLDOWN_MS) {

		if (posPlayer.y > m_y - 100 && posPlayer.y < m_y + 100) {

			Bullet* bul = new Bullet(pos.x, pos.y, -300, 0);


			last_shot_time = current_time;
			COOLDOWN_MS = 500 + (rand() % 300);
			ProjectileManager::Get()->AddProjectileEnemies(bul);
		}
	}

	return nullptr;
}