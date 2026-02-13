#include "Obstacle1.h"
#include "Bullet.h"


Obstacle1::Obstacle1(int x, int y) : Enemy(x, y, 50, 50, 2, 1, 200) {

}


void Obstacle1::MoveC(float deltaTime) {
	Move(-m_speed * deltaTime, 0 * deltaTime);

}

void Obstacle1::Draw(SDL_Renderer* renderer) {
	
	SDL_Texture* texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Obstacles.png");
	SDL_Rect rectDest = { m_x, m_y, m_width,m_height};
	SDL_Rect rectSrc;
	if (m_hp > m_maxHp/2) {
		rectSrc = { 700, 10, 900, 900};
	}
	else {
		rectSrc = { 700, 980, 900, 900 };
	}
	

	SDL_RenderCopy(renderer, texture, &rectSrc, &rectDest);

}


Projectile* Obstacle1::attack() {
	return nullptr;
}