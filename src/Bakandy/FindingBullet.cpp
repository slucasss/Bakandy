#include "FindingBullet.h"



FindingBullet::FindingBullet(int x, int y, int mx = 10, int my = 10) : Projectile(x, y, 30, 30, 2, mx, my) {



}

bool FindingBullet::MoveP(float deltaTime) {
	std::vector<Enemy*>* enemies = EnemyManager::Get()->GetEnemies();
	
	if (enemies->size() == 0) {
		return false;
	}

	Enemy* closest = (*enemies)[0];

	Vector2f pos = closest->GetPosition(0.5, 0.5);


	float closestDst = ((pos.x - m_x) * (pos.x - m_x)) + ((pos.y - m_y) * (pos.y - m_y) );
	
	for (Enemy* e : *enemies) {
		pos = e->GetPosition(0.5, 0.5);
		float dst = ((pos.x - m_x) * (pos.x - m_x)) + ((pos.y - m_y) * (pos.y - m_y) );

		if (dst < closestDst) {
			closestDst = dst;
			closest = e;
		}
	}


	Move( (((pos.x - m_x)/sqrt(closestDst))* 300) * deltaTime, (((pos.y - m_y) / sqrt(closestDst)) * 300) * deltaTime );


	return true;
}

void FindingBullet::Draw(SDL_Renderer* renderer)
{
	SDL_Texture* texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Projectiles.png");

	SDL_Rect rectDest = { m_x, m_y, m_width,m_height };
	SDL_Rect rectSrc = { 1630, 1550, 250, 300 };

	SDL_RenderCopy(renderer, texture, &rectSrc, &rectDest);
}