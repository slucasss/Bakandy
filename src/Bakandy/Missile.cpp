
#include "Missile.h"


Missile::Missile(int x, int y, int mx = 10, int my = 0) : Projectile(x, y, 15, 15, 1, mx, my){
}


bool Missile::MoveP(float deltaTime) {
	Move(m_MoveX * deltaTime, m_MoveY * deltaTime);
	if (m_x < -100 || m_x > 1300 || m_y < -100 || m_y > 700) {
		return false;
	}
	return true;
}


void Missile::Draw(SDL_Renderer* renderer)
{
	SDL_Texture* texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Projectiles.png");

	SDL_Rect rectDest = { m_x, m_y, m_width,m_height };
	SDL_Rect rectSrc = { 500, 1500, 200, 330 };

	SDL_RenderCopy(renderer, texture, &rectSrc, &rectDest);
}