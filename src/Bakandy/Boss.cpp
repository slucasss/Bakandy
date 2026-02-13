#include "Boss.h"
#include "Bullet.h"


Boss::Boss(int x, int y, Player * p) : Enemy(x, y, 223, 106, 40, 1, 100), m_p(p), timerAttack(0), timer(0), random(-1), AttackState(0) {


}

void Boss::MoveC(float deltaTime) {
	uint32_t current_time = SDL_GetTicks();
	if (random == -1) {
		if (current_time - timerAttack > 2000) {
			random = rand() % 5;
		}
	}

	else if (random == 0) {
		if (timer == 0) {
			timer = current_time;
		}
		if (current_time - timer > 4000) {
			if (m_x > 100 && AttackState != 2) {
				Move(-1000 * deltaTime, 0);
			}
			else {
				AttackState = 2;
			}
			if (AttackState == 2) {
				if (m_x < 1000) {
					Move(500 * deltaTime, 0);
				}
				else {
					AttackState = 0;
					random = -1;
					timer = 0;
					timerAttack = current_time;
				}
			
			
			}	
		}
		else {
			Vector2f posPlayer = m_p->GetPosition();
			Vector2f posBoss = GetPosition();
			/*if(posBoss.y +50 > posPlayer.y || posBoss.y - 50 < posPlayer.y){

			}*/
			if (posPlayer.y < posBoss.y) {
				Move(0, -200 * deltaTime);
			}
			else {
				Move(0, 200 * deltaTime);
			}
		}

	}
	
	else if (random == 1) {
		if (timer == 0) {
			timer = current_time;
			EnemyManager::Get()->AddEnemy(new Enemie3(1100, 100, m_p));
			EnemyManager::Get()->AddEnemy(new Enemie3(1100, 500, m_p));
		}
		
		if (current_time - timer > 3000) {
			timer = 0;
			random = -1;
			timerAttack = current_time;
		}
		
	}
	
	else if (random == 2) {
		if (timer == 0) {
			timer = current_time;
			EnemyManager::Get()->AddEnemy(new Enemie1(1100, 300, m_p));
			EnemyManager::Get()->AddEnemy(new Enemie1(1100, 400, m_p));
		}

		if (current_time - timer > 3000) {
			timer = 0;
			random = -1;
			timerAttack = current_time;
		}
	}

	else if (random == 3) {
		int r = rand() % 10;
		std::cout << r << std::endl;
		for (int i = 0; i < 12; i++) {
			if (i == r) {
				i += 2 ;
			}
			ProjectileManager::Get()->AddProjectileEnemies(new Bullet(900, i * 50, -100, 0));
		}
		timer = 0;
		random = -1;
		timerAttack = current_time;
	}

	else if (random == 4) {
		if (timer == 0) {
			timer = current_time;
		}
		if (current_time - timer < 4000) {
			if (AttackState == 0 && m_y > 500) {
				AttackState = 1;
			}
			else if (AttackState == 1 && m_y < 100) {
				AttackState = 0;
			}

			if (AttackState == 0) {
				Move(0, 200*deltaTime);
			}
			else if (AttackState == 1) {
				Move(0, -200 * deltaTime);
			}
		}
		else {
			AttackState = 0; 
			timer = 0;
			random = -1;
			timerAttack = current_time;
		}
	}
}

void Boss::Draw(SDL_Renderer* renderer) {
	SDL_Texture* texture = nullptr;
	if (m_speed != 0) {
		texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Spaceship2.png");
	}
	else {
		texture = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Spaceship2WithoutFire-removebg-preview.png");
	}
	SDL_Rect rectDest = { m_x, m_y, m_width,m_height };
	SDL_Rect rectSrc = { 1030, 520, 470, 200 };

	SDL_RenderCopy(renderer, texture, &rectSrc, &rectDest);


}

Projectile* Boss::attack() {

	Vector2f pos = GetPosition(0.1, 0.5);
	Uint32 current_time = SDL_GetTicks();

	if (current_time > last_shot_time + COOLDOWN_MS) {
		Bullet* bul = new Bullet(pos.x, pos.y, -300, 0);


		last_shot_time = current_time;


		COOLDOWN_MS = 700;

		ProjectileManager::Get()->AddProjectileEnemies(bul);
		
	}

	return nullptr;
}