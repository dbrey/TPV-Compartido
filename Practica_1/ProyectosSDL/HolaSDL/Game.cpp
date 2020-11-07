
#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>

Game::Game(SDL_Window* window, SDL_Renderer* renderer, int vx, int  vy, int  ctx, int cty) {
	window_ = window;
	renderer_ = renderer;
	VentX = vx, VentY = vy, tamCellX = ctx, tamCellY = cty;
	Inicializa();
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
		
		int aux;

		int contf = 0;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				input >> aux;
				if (aux == 1)
				{
					mapa->writeCell(i, j, Wall);
				}
				else if (aux == 2)
				{
					mapa->writeCell(i, j, Food);
					comida++;
				}
				else if (aux == 3)
				{
					mapa->writeCell(i, j, Vitamins);
				}
				else {
					mapa->writeCell(i, j, Empty);
					if (aux == 9)
					{
						//pac = new PacMan( int i, int j, textures[?]);
					}
					else if (aux == 5 || aux == 6 || aux == 7 || aux == 8)
					{
						//fantasmas[contf] = new Ghots(...)
						contf++;
					}
				}
			}
		}
	}
	// Cerramos el input
	input.close();
	return read;
}

void Game::Inicializa()
{
	//Crear texturas
	for (int i = 0; i < NUM_TEXTURES; ++i)
	{
		textures[i] = new Texture( renderer_, TEXTURE_ATRIBS[i].fileName, TEXTURE_ATRIBS[i].numRows, TEXTURE_ATRIBS[i].numCols);
	}
}

