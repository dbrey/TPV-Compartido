#pragma once

#include "Texture.h"
#include "GameMap.h"
#include "PacMan.h"
#include "Ghost.h"
class Game
{
private:

	int VentX, VentY, tamCellX, tamCellY, comida;
	bool exit;
	PacMan* pacman;
	GameMap* mapa;
	// Array de punteros a fantasmas Ghost* fantasmas[];
	//Puntero Ventana
	//Puntero Renderer
	// Array de texturas
	

public:

	Game(int vx, int  vy, int  ctx, int cty, int c, PacMan* p, GameMap* m) { VentX = vx, VentY = vy, tamCellX = ctx, tamCellY = cty, comida = c, pacman = p, mapa = m; };

	bool LeeArchivo(string archivo);
};