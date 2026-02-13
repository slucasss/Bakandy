#include "Enemie1.h"
#include "Bullet.h"


Enemie1::Enemie1(int x, int y, Player* p) : Enemy(x, y, 113, 53, 2, 1, 100), m_p(p) {

}


void Enemie1::MoveC(float deltaTime) {
	if (m_x > 500) {
		m_speed = 100;
	}
	else {
		m_speed = 0;
	}
	Move(-m_speed * deltaTime, 0 * deltaTime);

}

void Enemie1::Draw(SDL_Renderer* renderer) {
	SDL_Texture* texture = nullptr;
	if (m_speed != 0) {
		texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Spaceship2.png");
	}
	else {
		texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Spaceship2WithoutFire-removebg-preview.png");
	}
	SDL_Rect rectDest = {m_x, m_y, m_width,m_height};
	SDL_Rect rectSrc = { 1030, 50, 470, 200 };

	SDL_RenderCopy(renderer, texture, &rectSrc, &rectDest);


}


Projectile* Enemie1::attack() {
	

	Vector2f posPlayer = (*m_p).GetPosition();
	Vector2f pos = GetPosition(0.1, 0.5);
	Uint32 current_time = SDL_GetTicks();
	
		if (current_time > last_shot_time + COOLDOWN_MS) {

			if (posPlayer.y > m_y - 100 && posPlayer.y < m_y + 100) {

				Bullet* bul = new Bullet(pos.x, pos.y, -300, 0);
				

				last_shot_time = current_time;
				COOLDOWN_MS = 500 + (rand() % 500);
				ProjectileManager::Get()->AddProjectileEnemies(bul);
			}
		}

	return nullptr;
}