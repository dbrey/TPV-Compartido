
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

bool Game::LeeArchivo(string archivo) {
	bool read = true;  ifstream input;
    input.open(archivo);

	if (!input.is_open()) {
		cout << "Fichero no encontrado\n";
		read = false;
	}
	else {
		int x, y;
		input >> x >> y;

		mapa = new GameMap(x, y, this);
		
		int aux, contf = 0;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				input >> aux;
				if (aux == 1)
					mapa->writeCell(j, i, Wall);
				else if (aux == 2) {
					mapa->writeCell(j, i, Food);
					comida++;
				}
				else if (aux == 3)
					mapa->writeCell(j, i, Vitamins);
				else {
					mapa->writeCell(j, i, Empty);
					if (aux == 9)
						pac = new PacMan(j,i, this);
					else if ((aux == 5 || aux == 6 || aux == 7 || aux == 8) && contf <4) {
						fantasmas[contf] = new Ghost(j , i, this);
						contf++;
					}
				}
			}
		}
	}
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
	pac->update();
	for (int i = 0; i < fantasmas.size(); i++)
	{
		fantasmas[i]->update();
	}

	SDL_Delay(235);
}

bool Game::nextCell(Vector2D dir, Point2D pos)
{
	if (dir.GetX() == -1) {
		return	(getMapa()->readCell(pos.getX() - 1, pos.getY()) != Wall);
	}
	else if (dir.GetX() == 1) {
		return (getMapa()->readCell(pos.getX() + 1, pos.getY()) != Wall);
	}
	else if (dir.GetY() == -1) {
		return getMapa()->readCell(pos.getX(), pos.getY() - 1) != Wall;
	}
	else if (dir.GetY() == 1) {
		return (getMapa()->readCell(pos.getX(), pos.getY() + 1) != Wall);
	}

}

void Game::run() {
	SDL_Event event;
	while (!fin() && pac->returnLives() > 0)
	{
		SDL_RenderClear(renderer_);
		render();
		if (SDL_PollEvent(&event) != 0)
		{
			handleEvent(event);
		}
		update();
		

		SDL_RenderPresent(renderer_);
	}
	
}

Game::~Game()
{
	pac->~PacMan();
	for (int i = 0; i < fantasmas.size(); i++)
	{
		fantasmas[i]->~Ghost();
	}

	mapa->~GameMap();

	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	SDL_Quit();
}