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
	bool aux = false;
	SDL_Rect r;
	int i = 0, j = 0;
	while (!aux)
	{
		while (!aux)
		{
			if (Mapa[i][j] == Wall)
			{
				r = mapCoordsToSDLPoint()
			}

			j++;
		}
		i++;
	}
	
}

SDL_Point GameMap::mapCoordsToSDLPoint(Point2D& p)
{

	//Averiguar que casilla del mapa corresponde al p

	//Averiguar la relacion entre la casilla del mapa con la ventana

	//

	SDL_Point aux;
	
	aux.x =( xcasilla*800)/tamañojuegox
	aux.y = (ycasilla*600)/tamañojuegoy
	return aux;
}

Point2D GameMap::SDLPointToMapCoords(SDL_Point& Sp)
{
	Point2D aux

		auxx = (sp.x *casillas del mapa x )/800
	return aux;
}

GameMap::~GameMap()
{
	delete Mapa;
	delete game;
}