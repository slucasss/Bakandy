#include <iostream>
#include "MenuManager.h"


MenuManager* MenuManager::Instance = nullptr;

MenuManager* MenuManager::Get() {
	if (Instance == nullptr) {
		Instance = new MenuManager;
	}
	return Instance;
}

int MenuManager::Menu(SDL_Renderer* renderer) {
	SDL_Texture* background = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Background2.png");
	SDL_Texture* PlayButton = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Buttons/ButtonPlayOff.png");
	SDL_Texture* CrButton = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Buttons/Button.png");
	SDL_Texture* ExitButton = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Buttons/Button.png");
	SDL_Texture* TutoButton = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Buttons/Button.png");
	SDL_Texture* Title = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Title.png");

	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, background, NULL, NULL);

	SDL_Rect rectSrc;

	SDL_Rect rectDst = { 514, 180, 172, 88};
	SDL_RenderCopy(renderer, PlayButton, NULL, &rectDst);

	rectSrc = { 410, 45, 310, 160 };
	rectDst = { 514, 280, 172, 88 };
	SDL_RenderCopy(renderer, CrButton, &rectSrc, &rectDst);

	rectSrc = { 410, 215, 310, 160 };
	rectDst = { 514, 480, 172, 88 };
	SDL_RenderCopy(renderer, ExitButton,  &rectSrc, &rectDst);

	rectSrc = { 79, 390, 310, 160 };
	rectDst = { 514, 380, 172, 88 };
	SDL_RenderCopy(renderer, TutoButton, &rectSrc, &rectDst);

	rectDst = { 350, -30, 500, 300 };
	SDL_RenderCopy(renderer, Title, NULL, &rectDst);

	SDL_RenderPresent(renderer);


	while (true){
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				int x = event.button.x;
				int y = event.button.y;

				if (x > 514 && x < 686) {
					if (y > 180 && y < 268) {
						//Play Button
						return 1;
					}
					else if (y > 280 && y < 368) {
						//Credits Button
						return 2;
					}
					else if (y > 380 && y < 468) {
						//tuto Button
						return 3;
					}
					else if (y > 480 && y < 568) {
						//Quit Button
						return 4;
					}
				}
			}


		}
	}
}

void MenuManager::Credits(SDL_Renderer * renderer) {
	SDL_RenderClear(renderer);

	SDL_Texture* background = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Background2.png");
	SDL_Texture* ExitButton = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Buttons/ExitButton.png");
	SDL_Texture* Credits = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Credits.png");

	SDL_RenderCopy(renderer, background, NULL, NULL);

	SDL_RenderCopy(renderer, Credits, NULL, NULL);

	SDL_Rect rectDst = { 950, 460, 233, 116 };
	SDL_RenderCopy(renderer, ExitButton, NULL, &rectDst);

	SDL_RenderPresent(renderer);

	while (true) {
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				int x = event.button.x;
				int y = event.button.y;

				if (x > 950 && x < 1183 && y > 460 && y < 576) {
					return;
				}

			}
		}
	}


}

void MenuManager::Tuto(SDL_Renderer* renderer) {
	SDL_Texture* background = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Background2.png");
	SDL_Texture* ExitButton = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Buttons/ExitButton.png");
	SDL_Texture* Tuto = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Tuto.png");

	SDL_RenderCopy(renderer, background, NULL, NULL);

	SDL_Rect Rectdst = { 200, 0, 800 , 600 };
	SDL_RenderCopy(renderer, Tuto, &Rectdst, NULL);

	SDL_Rect rectDst = { 950, 460, 233, 116 };
	SDL_RenderCopy(renderer, ExitButton, NULL, &rectDst);

	SDL_RenderPresent(renderer);

	while (true) {
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				int x = event.button.x;
				int y = event.button.y;

				if (x > 950 && x < 1183 && y > 460 && y < 576) {
					return;
				}

			}
		}
	}
}

void MenuManager::GameOverMenu(SDL_Renderer* renderer) {
	SDL_Texture* background = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Background2.png");
	SDL_Texture* ExitButton = AssetManager::Get()->LoadTexture(renderer, "../../Assets/Buttons/ExitButton.png");
	SDL_Texture* LoseMessage = AssetManager::Get()->LoadTexture(renderer, "../../Assets/WinLose.png");

	SDL_RenderCopy(renderer, background, NULL, NULL);

	//SDL_Rect Rectdst = { 200, 0, 800 , 600 };
	SDL_Rect rectSrc = { 160, 310, 410, 140 };
	SDL_RenderCopy(renderer, LoseMessage, &rectSrc, NULL);

	SDL_Rect rectDst = { 950, 460, 233, 116 };
	SDL_RenderCopy(renderer, ExitButton, NULL, &rectDst);

	SDL_RenderPresent(renderer);

	while (true) {
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				int x = event.button.x;
				int y = event.button.y;

				if (x > 950 && x < 1183 && y > 460 && y < 576) {
					return;
				}

			}
		}
	}
}