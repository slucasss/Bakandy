#include "LevelManager.h"


LevelManager* LevelManager::Instance = nullptr;


LevelManager* LevelManager::Get() {
	if (Instance == nullptr) {
		Instance = new LevelManager;
	}
	return Instance;
}

bool LevelManager::LoadLevel(const char* path) {
	for (auto l : level) {
		l.clear();
	}

	std::ifstream file(path);
	std::string line;
	while (std::getline(file, line)) {
		std::vector<char> lineChars;
		for (char c : line) {
			lineChars.push_back(c);
		}
		level.push_back(lineChars);
	}
	LastTimeSpawn = 0;
	index = 0;
	return true;
}

void LevelManager::LevelSpawn() {

	int Cooldown = 1000;
	Uint32 current_time = SDL_GetTicks();

	
	if(current_time - LastTimeSpawn >= 1000){
		if (index < level[0].size()) {
			for (int i = 0; i < 6; i++) {
				switch (level[i][index]) {
				case 'x':
					EnemyManager::Get()->AddEnemy(new Enemie1(1150, (i * 100)+50, PlayerManager::Get()->GetPlayer()));
					break;

				case 'c':
					EnemyManager::Get()->AddEnemy(new Enemie2(1150, (i * 100) + 50, PlayerManager::Get()->GetPlayer()));
					break;

				case 'a':
					EnemyManager::Get()->AddEnemy(new Enemie3(1150, (i * 100) + 50, PlayerManager::Get()->GetPlayer()));
					break;

				case 'b':
					EnemyManager::Get()->AddEnemy(new Boss(1150, (i * 100) + 50, PlayerManager::Get()->GetPlayer()));
					break;

				case 'o':
					ObstacleManager::Get()->AddObstacles(new Obstacle1(1150, (i * 100) + 50));
					break;
				case 'g':
					ObstacleManager::Get()->AddObstacles(new Obstacle2(1150, (i * 100) + 50));
					break;

				}
			}
			LastTimeSpawn = current_time;
			index += 1;
		}
	}	

}

void LevelManager::InitRender(SDL_Renderer* renderer) {
	
	background.push_back(new Image(renderer, "../../Assets/Background2.png"));
	background[0]->Resize(1200, 1200);

	background.push_back(new Image(renderer, "../../Assets/Background2.png"));
	background[1]->Resize(1200, 1200);
	background[1]->SetPosition(1200, 0, 0, 0);



	mid.push_back(new Image(renderer, "../../Assets/Mid-removebg-preview.png"));
	mid[0]->Resize(600, 600);

	mid.push_back(new Image(renderer, "../../Assets/Mid-removebg-preview.png"));
	mid[1]->Resize(600, 6000);
	mid[1]->SetPosition(600, 0, 0, 0);

	mid.push_back(new Image(renderer, "../../Assets/Mid-removebg-preview.png"));
	mid[2]->Resize(600, 6000);
	mid[2]->SetPosition(1200, 0, 0, 0);

	

	front.push_back(new Image(renderer, "../../Assets/Front-removebg-preview.png"));
	front[0]->Resize(600, 600);

	front.push_back(new Image(renderer, "../../Assets/Front-removebg-preview.png"));
	front[1]->Resize(600, 6000);
	front[1]->SetPosition(600, 0, 0, 0);
	
	front.push_back(new Image(renderer, "../../Assets/Front-removebg-preview.png"));
	front[2]->Resize(600, 6000);
	front[2]->SetPosition(1200, 0, 0, 0);


}

void LevelManager::RenderLevel(SDL_Renderer* renderer, float deltaTime){
	
	//Background
	for (Image* b : background) {
		b->Move(-2, 0);
		Vector2f pos = b->GetPosition(1, 0);
		if (pos.x < 0) {
			b->SetPosition(1190, 0, 0, 0);
		}
		b->Draw(renderer);
	}

	//Mountain

	for (Image* m : mid) {
		m->Move(-3, 0);
		Vector2f pos = m->GetPosition(1, 0);
		if (pos.x < 0) {
			m->SetPosition(1190, 0, 0, 0);
		}
		m->Draw(renderer);
	}

	//Sugar canne
	for (Image* f : front) {
		f->Move(-6, 0);
		Vector2f pos = f->GetPosition(1, 0);
		if (pos.x < 0) {
			f->SetPosition(1190, 0, 0, 0);
		}
		f->Draw(renderer);
	}
}

void LevelManager::RenderLevelInPause(SDL_Renderer* renderer) {
	//Background
	for (Image* b : background) {
		b->Draw(renderer);
	}

	//Mountain

	for (Image* m : mid) {
		m->Draw(renderer);
	}

	//Sugar canne
	for (Image* f : front) {
		f->Draw(renderer);
	}
}

void LevelManager::ClearAll(SDL_Renderer* renderer) {
	EnemyManager::Get()->Clear();
	PlayerManager::Get()->Clear();
	ProjectileManager::Get()->Clear();
	for (int i = background.size() - 1; i >= 0; i--) {
		Image* a = background[i];
		background.erase(background.begin() + i);
		delete(a);
	}
	for (int i = mid.size() - 1; i >= 0; i--) {
		Image* a = mid[i];
		mid.erase(mid.begin() + i);
		delete(a);
	}
	for (int i = front.size() - 1; i >= 0; i--) {
		Image* a = front[i];
		front.erase(front.begin() + i);
		delete(a);
	}

	InitRender(renderer);
}