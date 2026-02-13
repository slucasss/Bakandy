#include <SDL.h>
#include <iostream>
#include "Player.h"

#include "Missile.h"



Player::Player(int x, int y) : Character(x, y, 140, 60, 10, 50, 400), moving(false), LastTimeHit(0) {

}

void Player::HaveDamage(int dmg) {
	Uint32 currentTime = SDL_GetTicks();
	if ((currentTime - LastTimeHit) > 2000) {
		LastTimeHit = currentTime;
		takeDamage(dmg);
	}
}

void Player::Draw(SDL_Renderer* renderer) {
	SDL_Texture* texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/SpaceshipForPlayer.png");

	SDL_Rect rectSrc;

	if (moving == true) {
		rectSrc = { 650, 742, 600, 250 };
	}
	else {
		rectSrc = { 650, 1200, 600, 250 };
	}
	SDL_Rect rectDest = { m_x, m_y, m_width,m_height };
	SDL_RenderCopy(renderer, texture, &rectSrc, &rectDest);



	SDL_Texture* hearth = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Hearth.png");
	for (int i = 0; i < m_hp; i++) {
		SDL_Rect rectDst = { 20 + (40*i), 20, 30, 30 };
		SDL_Rect rectSrc = { 983, 220, 686, 654 };

		SDL_RenderCopy(renderer, hearth, &rectSrc, &rectDst);
	}
	
	for (int i = 0; i < m_maxHp - m_hp; i++) {
		SDL_Rect rectDst = { 20 + (m_hp*40) + (40 * i), 20, 30, 30};
		SDL_Rect rectSrc = { 107, 219, 686, 654 };

		SDL_RenderCopy(renderer, hearth, &rectSrc, &rectDst);
	}
}

void Player::MoveC(float deltaTime) {
}

Projectile* Player::attack(){
	Vector2f pos = GetPosition(0.9, 0.5);

	/*int x;
	int y;
	SDL_GetMouseState(&x, &y);


	float SPX;
	float SPY;

	float disX = x - ;
	float disY*/


	Missile* Mis = new Missile(pos.x,pos.y, 300, 0);
	return Mis;
}



