#include "GameMap.h"
#include "Game.h" // Necesario? Tenemos Game en GameObject, pero quitarlo da errores

// Constructora
GameMap::GameMap(int c, int f, Game* g,int x,int y) : GameObject(Point2D (0,0), x , y, g)
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
			destRect.x = i* w;
			destRect.y = j* h;
			destRect.w = w;
			destRect.h = h;

			if (Mapa[i][j] == Wall)
			{
				if (game->getTexture(wall) == NULL)
				{
					string aux = "muro";
					throw FileNotFoundError(aux);
				}
				else game->getTexture(wall)->render(destRect);
			}
			else if (Mapa[i][j] == Vitamins)
			{
				if (game->getTexture(burguer) == NULL)
				{
					string aux = "burger";
					throw FileNotFoundError(aux);

				}
				else game->getTexture(burguer)->render(destRect);
			}
			else if (Mapa[i][j] == Food)
			{
				if (game->getTexture(food) == NULL)
				{
					string aux = "food";
					throw FileNotFoundError(aux);
				}
				else game->getTexture(food)->render(destRect);
			}	
		}
	}
}

void GameMap::update() {}

Point2D GameMap::SDLPointToMapCoords(int x, int y)
{
	Point2D aux = Point2D((x / w), (y / h));
	return aux;
}

// Comprobamos si intersecta el personaje con alguna pared
bool GameMap::intersectsWall(const SDL_Rect& rect, bool g)
{
	Point2D topLeft = SDLPointToMapCoords(rect.x, rect.y);
	Point2D botRight = Point2D(0,0);
	if (g)
	{
		botRight = SDLPointToMapCoords((rect.x + rect.h - 1), (rect.y + rect.w - 1));
	}
	else
	{
		botRight = SDLPointToMapCoords((rect.x + rect.w - 1), (rect.y + rect.h - 1));
	}

	// Teniendo en cuenta que se forma un rectangulo que conforma al personaje, miramos si dentro de dicho rectangulo intersecciona con un
	for (int c = topLeft.getX(); c <= botRight.getX(); c++)
	{
		for (int r = topLeft.getY();r <= botRight.getY(); r++)
		{
			if (c<fils && r<cols && readCell(c,r) == Wall)
				return true;
		}
	}	
	return false;
}

// Cogemos el tamaño del mapa
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
	delete[] Mapa;
}