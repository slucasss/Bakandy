
#pragma once
#include <map>
#include <string>
struct SDL_Texture;
struct SDL_Renderer;

class AssetManager
{
	static AssetManager* Instance;

	std::map<std::string , SDL_Texture*> m_textures;

public:
	static AssetManager* Get();

	
	SDL_Texture* LoadTexture(SDL_Renderer* renderer, const std::string& path);

};


