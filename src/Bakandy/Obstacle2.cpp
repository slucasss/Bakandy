#include "Obstacle2.h"
#include "Bullet.h"


Obstacle2::Obstacle2(int x, int y) : Enemy(x, y, 50, 70, 4, 1, 200) {

}


void Obstacle2::MoveC(float deltaTime) {
	Move(-m_speed * deltaTime, 0 * deltaTime);

}

void Obstacle2::Draw(SDL_Renderer* renderer) {

	SDL_Texture* texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Obstacles.png");
	SDL_Rect rectDest = { m_x, m_y, m_width,m_height };
	SDL_Rect rectSrc;
	if (m_hp > m_maxHp / 2) {
		rectSrc = { 10, 10, 480, 897 };
	}
	else {
		rectSrc = { 10, 915, 480, 897 };
	}

	SDL_RenderCopy(renderer, texture, &rectSrc, &rectDest);

}


Projectile* Obstacle2::attack() {
	return nullptr;
}