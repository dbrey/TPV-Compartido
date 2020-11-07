#pragma once

#include "Vector2D.h"
#include "Texture.h"
#include "GameMap.h"
class Game;

class PacMan
{
private:

	int vidas = 3;
	int energia;

	Point2D point;
	Vector2D dir;
	//Texture* pac;
	GameMap* mapa; 
	// Puntero a Game
public:
	
	/*PacMan(int x, int y, Texture* tTexture) { point(x, y); pac = tTexture; }*/

	void HandleEvent(SDL_Event tecla);
	void Render();
	void Actualizar();
};