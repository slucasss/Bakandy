#pragma once
#include <SDL.h>

#include "AssetManager.h"
#include "GameManager.h"
class MenuManager
{

private:
	static MenuManager* Instance;

public:
	static MenuManager* Get();
	
	int Menu(SDL_Renderer* renderer);

	void Credits(SDL_Renderer* renderer);

	void Tuto(SDL_Renderer* renderer);

	void GameOverMenu(SDL_Renderer* renderer);

};

