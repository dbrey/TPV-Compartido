#include "GameMap.h"
#include "Game.h"

// Constructora
GameMap::GameMap(int c, int f, Game* g)
{
	cols = c;
	fils = f;
	Mapa = new MapCell* [cols];
	game = g;

	for (int i = 0; i < cols; i++)
	{
		Mapa[i] = new MapCell [fils];
	}
}

// Renderiza todo el mapa y sus elementos del juego
void GameMap::render() {
	for (int i = 0; i < fils; i++) {
		for (int j = 0; j < cols; j++) {
			SDL_Rect destRect;
			destRect.x = i * 10;
			destRect.y = j * 10;
			destRect.w = 10;
			destRect.h = 10;

			if (Mapa[i][j] == Wall)
			{
				if (game->getTexture(wall) == NULL)
				{
					throw "No hay textura de muro";
				}
				else game->getTexture(wall)->render(destRect);
			}
			else if (Mapa[i][j] == Vitamins)
			{
				if (game->getTexture(burguer) == NULL)
				{
					throw "No hay textura de burger";
				}
				else game->getTexture(burguer)->render(destRect);
			}
			else if (Mapa[i][j] == Food)
			{
				if (game->getTexture(food) == NULL)
				{
					throw "No hay textura food";
				}
				else game->getTexture(food)->render(destRect);
			}	
		}
	}
}

bool GameMap::intersectsWall(const SDL_Rect& rect)
{
	Point2D topLeft = SDLPointToMapCoords(rect.x, rect.y);
	Point2D botRight = SDLPointToMapCoords((rect.x + rect.w), (rect.y+rect.h));

	// Teniendo en cuenta que se forma un rectangulo que conforma al personaje, miramos si dentro de dicho rectangulo intersecciona con un
	for (int r = topLeft.getX(); r <= botRight.getX(); r++)
	{
		for (int c = topLeft.getY(); c <= botRight.getY(); c++)
		{
			if (readCell(r, c) == Wall)
				return true;
		}
	}	
}

SDL_Point GameMap::mapCoordsToSDLPoint(Point2D& coords)
{
	SDL_Point aux;

	aux.x = (coords.getX() * 800) / cols*10;
	aux.y = (coords.getY() * 600) / fils * 10;
	return aux;
}

Point2D GameMap::SDLPointToMapCoords(int x, int y)
{
	Point2D aux = Point2D((x * cols) / 800, (y*fils) / 600);
	return aux;
}

GameMap::~GameMap()
{
	delete Mapa;
	delete game;
}