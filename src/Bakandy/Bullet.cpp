
#include "Bullet.h"


Bullet::Bullet(int x, int y, int mx = 10, int my = 0): Projectile(x, y, 30, 30, 1, mx, my){

}


bool Bullet::MoveP(float deltaTime) {
	Move(m_MoveX * deltaTime, m_MoveY * deltaTime);
	if (m_x < -100 || m_x > 1300 || m_y < -100 || m_y > 700) {
		return false;
	}
	return true;
}


void Bullet::Draw(SDL_Renderer* renderer)
{
	SDL_Texture* texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Projectiles.png");

	SDL_Rect rectDest = { m_x, m_y, m_width,m_height };
	SDL_Rect rectSrc = { 1620, 250, 250, 360 };

	SDL_RenderCopy(renderer, texture, &rectSrc, &rectDest);
}