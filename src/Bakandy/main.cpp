#include "GameManager.h"



int main(int argc, char** argv)
{
	GameManager::Get()->Init();
	while (true)
	{
		if (GameManager::Get()->GameLoop() == 0) {
			break;
		}
	}
	GameManager::Get()->End();
	return 0;
}
