#pragma once
#include <fstream>
#include <sstream>

#include "EnemyManager.h"
#include "PlayerManager.h"
#include "AssetManager.h"
#include "ObstacleManager.h"

#include "Enemie1.h"
#include "Enemie2.h"
#include "Enemie3.h"
#include "Boss.h"
#include "Image.h"
#include "Obstacle1.h"
#include "Obstacle2.h"


class LevelManager
{
private:

	static LevelManager* Instance;

	std::vector<std::vector<char>> level;

	//Spawn enemies

	Uint32 LastTimeSpawn;
	int index;


	//Render

	std::vector<Image*>background;
	std::vector<Image*>mid;
	std::vector<Image*>front;



public:
	static LevelManager* Get();

	bool LoadLevel(const char* path = "../../src/Bakandy/Level.txt");

	void LevelSpawn();

	void InitRender(SDL_Renderer* renderer);

	void RenderLevel(SDL_Renderer* renderer, float deltaTime);

	void RenderLevelInPause(SDL_Renderer* renderer);

	void ClearAll(SDL_Renderer* renderer);


};


