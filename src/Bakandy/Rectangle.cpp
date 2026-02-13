#include <SDL.h>
#include "Rectangle.h"



Rectangle::Rectangle(int width, int height) : Geometry(width, height)
{
}

void Rectangle::Draw(SDL_Renderer* renderer)
{
	SDL_Rect rect = { m_x, m_y, m_width, m_height };

	SDL_RenderDrawRect(renderer, &rect);
}