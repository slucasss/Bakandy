#include "GameManager.h"
#include <stdlib.h>
//#include <SDL_mixer.h>



#define WIDTH 1200
#define HEIGHT 600

#define CENTER_X (WIDTH - 1) / 2
#define CENTER_Y (HEIGHT - 1) / 2

#define TARGET_FPS 60
#define TARGET_DELTA_TIME 1.f / TARGET_FPS

double FRAMECOUNT = 0;



GameManager* GameManager::Instance = nullptr;

GameManager* GameManager::Get()
{
	if (Instance == nullptr) {
		Instance = new GameManager;
	}
	return Instance;
}

void GameManager::Init() {
	

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	srand(time(NULL));

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
	{
		std::cout << "Error SDL2 Initialization : " << SDL_GetError();
		return;
	}

	window = SDL_CreateWindow("Bakandy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	if (window == NULL)
	{
		std::cout << "Error window creation";
		return;
	}
	SDL_Surface* icone = IMG_Load("../../Assets/Icone.png");
	SDL_SetWindowIcon(window, icone);
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		std::cout << "Error renderer creation";
		return;
	}


	/*Mix_Chunk* sound = Mix_LoadWAV("C:/Users/slucas/source/repos/lyo-1-c64-s1p6-14/projet6/Assets/MusiqueEpique.wav");

	if (sound == nullptr) {
		std::cout << "ca marche pas" << std::endl;
	}
	std::cout << Mix_PlayChannel(1, sound, -1) << std::endl;*/

	game = Menu;
	
}

int GameManager::GameLoop() {

	if (game == Party) {


		Uint64 start = SDL_GetTicks64();

		//EVENT
		InputManager::Get()->Update();

		if (InputManager::Get()->IsDown(SDLK_ESCAPE)) {
			game = Pause;
		}

		PlayerManager::Get()->Move(deltaTime);
		PlayerManager::Get()->Attack();


		EnemyManager::Get()->MoveEnemies(deltaTime);
		EnemyManager::Get()->AttackEnemies();

		ObstacleManager::Get()->MoveObstacles(deltaTime);


		ColisionManager::Get()->AllColision();

		if (EnemyManager::Get()->Death()) {
			game = Win;
		}


		ObstacleManager::Get()->Death();
		if (!PlayerManager::Get()->GetPlayer()->IsAlive()) {
			game = Lose;
		}


		ProjectileManager::Get()->MoveProjectiles(deltaTime);

		LevelManager::Get()->LevelSpawn();


		//Draw
		SDL_RenderClear(renderer);

		LevelManager::Get()->RenderLevel(renderer, deltaTime);


		ProjectileManager::Get()->DrawAllProjectiles(renderer);

		EnemyManager::Get()->DrawEnemies(renderer);

		ObstacleManager::Get()->DrawObstacles(renderer);

		PlayerManager::Get()->GetPlayer()->Draw(renderer);

		SDL_RenderPresent(renderer);


		//Fps check
		Uint64 end = SDL_GetTicks64();

		deltaTime = (end - start) / 1000.f;
		float diff = TARGET_DELTA_TIME - deltaTime;


		if (diff > 0)
		{
			SDL_Delay(diff * 1000);
			deltaTime = TARGET_DELTA_TIME;

		}
	}
	
	else if(game == Menu){
		int state = MenuManager::Get()->Menu(renderer);
		switch (state) {
		case 1:
			game = Party;

			LevelManager::Get()->LoadLevel();
			LevelManager::Get()->InitRender(renderer);
			break;
		case 2:
			game = Credits;
			break;
		case 3:
			game = Tuto;
			break;
		
		case 4:
			game = Quit;
			break;
		}

	}

	else if(game == Pause){

		InputManager::Get()->Update();
		
		if (InputManager::Get()->IsDown(SDLK_ESCAPE)) {
			game = Party;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		LevelManager::Get()->RenderLevelInPause(renderer);


		ProjectileManager::Get()->DrawAllProjectiles(renderer);

		EnemyManager::Get()->DrawEnemies(renderer);

		PlayerManager::Get()->GetPlayer()->Draw(renderer);

		SDL_RenderPresent(renderer);
	}
	
	else if (game == Credits) {
		MenuManager::Get()->Credits(renderer);
		game = Menu;
	}

	else if (game == Tuto) {
		MenuManager::Get()->Tuto(renderer);
		game = Menu;
	}

	else if (game == Quit) {
		End();
		return 0;
	}
	
	else if (game == Lose) {
		MenuManager::Get()->GameOverMenu(renderer);
		game = Menu;
		LevelManager::Get()->ClearAll(renderer);
	}

	else if (game == Win) {
		game = Credits;
		LevelManager::Get()->ClearAll(renderer);

	}

	return 1;
}

void GameManager::End() {
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}