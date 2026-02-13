#pragma once

#include <vector>
#include <iostream>
#include <SDL_image.h>
#include <filesystem>

#include "SDL.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Image.h"
#include "Bullet.h"

#include "PlayerManager.h"
#include "InputManager.h"
#include "ColisionManager.h"
#include "ProjectileManager.h"
#include "EnemyManager.h"
#include "LevelManager.h"
#include "MenuManager.h"
#include "ObstacleManager.h"

#include "Enemie1.h"
#include "Enemie2.h"
#include "Enemie3.h"






class GameManager
{
	static GameManager* Instance;

	SDL_Window* window;
	SDL_Renderer* renderer;

	float deltaTime = 0;

	enum GameState {Menu, Party, Pause, Win, Lose, Credits,Tuto, Quit};
	GameState game;


public:

	static GameManager* Get();

	void Init();

	int GameLoop();

	void End();
};

