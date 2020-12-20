#include "GameMap.h"
#include "Game.h"

// Constructora
GameMap::GameMap(int c, int f, Game* g) : GameObject(Point2D (0,0), g->CellX() , g->CellY(), g)
{
	cols = c;
	fils = f;
	Mapa = new MapCell* [cols];

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
			destRect.x = i*game->CellX();
			destRect.y = j*game->CellY();
			destRect.w = game->CellX();
			destRect.h = game->CellY();

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

void GameMap::update() {}

bool GameMap::intersectsWall(const SDL_Rect& rect)
{
	Point2D topLeft = game->SDLPointToMapCoords(rect.x, rect.y);
	Point2D botRight = game->SDLPointToMapCoords((rect.x + rect.w-1), (rect.y+rect.h-1));

	// Teniendo en cuenta que se forma un rectangulo que conforma al personaje, miramos si dentro de dicho rectangulo intersecciona con un
	for (int c = topLeft.getX(); c <= botRight.getX(); c++)
	{
		for (int r = topLeft.getY();r <= botRight.getY(); r++)
		{
			if (readCell(r,c) == Wall)
				return true;
		}
	}	

	return false;
}



SDL_Rect GameMap::getDestRect()
{
	SDL_Rect aux;
	aux.x = point.getX();
	aux.y = point.getY();

	aux.w = w*cols;
	aux.h = h*fils;
	return aux;
}


GameMap::~GameMap()
{
	delete Mapa;
	delete game;
}