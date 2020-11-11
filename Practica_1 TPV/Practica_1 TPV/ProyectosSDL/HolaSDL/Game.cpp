
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

		mapa = new GameMap(x, y, this);
		
		int aux;

		int contf = 0;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				input >> aux;
				if (aux == 1)
				{
					mapa->writeCell(j, i, Wall);
				}
				else if (aux == 2)
				{
					mapa->writeCell(j, i, Food);
					comida++;
				}
				else if (aux == 3)
				{
					mapa->writeCell(j, i, Vitamins);
				}
				else {
					mapa->writeCell(j, i, Empty);
					if (aux == 9)
					{
						pac = new PacMan(j,i, this);
					}
					else if ((aux == 5 || aux == 6 || aux == 7 || aux == 8) && contf <4)
					{
						fantasmas[contf] = new Ghost(j , i, this);
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

void Game::render() {
	mapa->render();
	pac->render();
	for (int i = 0; i < fantasmas.size(); i++)
	{
		fantasmas[i]->render(i);
	}
}

void Game::handleEvent(SDL_Event& tecla){
	pac->handleEvent(tecla);
}

void Game::update() {
	//pac->update();
	for (int i = 0; i < fantasmas.size(); i++)
	{
		fantasmas[i]->update();
	}
}


/*void Game::run() {
	update();
	render();
	handleEvent();
}*/

/*void Game::destroy() {
	delete
}*/