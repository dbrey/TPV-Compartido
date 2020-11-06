
#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>

Game::Game(SDL_Window* window, SDL_Renderer* renderer, int vx, int  vy, int  ctx, int cty) {
	window_ = window;
	renderer_ = renderer;
	VentX = vx, VentY = vy, tamCellX = ctx, tamCellY = cty;
	
	/*for (int i = 0; i < 4; i++)
	{
		fantasmas[i] = f[i];
	}*/
	LeeArchivo("level01.dat");
}

bool Game::LeeArchivo(string archivo)
{
	bool read = true;
    ifstream input;
    input.open(archivo);

	if (!input.is_open())
	{
		cout << "Fichero no encontrado\n";
		read = false;
	}
	else
	{
		int x, y;
		input >> x;
		input >> y;
		
		int aux2;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				input >> aux2;
				if (aux2 == 1)
				{
					mapa->writeCell(j, i, Wall);
				}
				else if (aux2 = 2)
				{
					mapa->writeCell(j, i, Food);
					comida++;
				}
				else if (aux2 = 3)
				{
					mapa->writeCell(j, i, Vitamins);
				}
				else {
					mapa->writeCell(j, i, Empty);
					if (aux2 == 9)
					{
						// pacman = new PacMan(Point2D(j,i), textures[?], ...);
					}
				}
			}
		}
	}
	// Cerramos el input
	input.close();
	return read;
}


Point2D Game::getPos(int x, int y)
{
	Point2D aux(0,0);
	aux.Suma(x, y);

	return aux;
}
void Game::Inicializa()
{




	//Crear texturas
	for (int i = 0; i < NUM_TEXTURES; ++i)
	{
		textures[i] = new Texture( renderer_, TEXTURE_ATRIBS[i].fileName, TEXTURE_ATRIBS[i].numRows, TEXTURE_ATRIBS[i].numCols);
	}
}

