
#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Game::Game(SDL_Window* window, SDL_Renderer* renderer, int vx, int  vy, int  ctx, int cty) {
	window_ = window;
	renderer_ = renderer;
	VentX = vx, VentY = vy, tamCellX = ctx, tamCellY = cty;
	IniTextures();
	LeeArchivo(nombreNivel(nMapa));
}

string Game::nombreNivel(int nMapa)
{
	stringstream nombre;
	nombre << "../mapas/level0" << nMapa << ".dat";
	return nombre.str();
}

// Lee el archivo y asigna los elementos del archivo a las variables de Game(PacMan,Ghost,Mapa...)
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
		
		int aux;
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
					else if ((aux == 5 || aux == 6 || aux == 7 || aux == 8)) {
						fantasmas.push_back(new Ghost(j, i, this));
					}
				}
			}
		}
	}
	input.close();
	return read;
}

// Inicializa las texturas del juego
void Game::IniTextures()
{
	for (int i = 0; i < NUM_TEXTURES; ++i)
	{
		textures[i] = new Texture( renderer_, TEXTURE_ATRIBS[i].fileName, TEXTURE_ATRIBS[i].numRows, TEXTURE_ATRIBS[i].numCols);
	}
}

Ghost* Game::getGhost(int i)
{
	int aux = 0;
	List<Ghost*>::Iterator it = fantasmas.begin();
	while (it != fantasmas.end() && aux != i)
	{
		aux++;
		++it;
	}

	return it.elem();
}

// Renderiza todos los elementos del juego
void Game::render() {
	SDL_RenderClear(renderer_);
	mapa->render();
	pac->render();
	
	int aux = 0;
	List<Ghost*>::Iterator it = fantasmas.begin();
	while (it != fantasmas.end())
	{
		it.elem()->render(aux);
		++it;
		aux++;
	}

	SDL_RenderPresent(renderer_);
}

// Maneja los eventos
void Game::handleEvent(SDL_Event& tecla){
	if (SDL_PollEvent(&tecla) != 0)
	{
		pac->handleEvent(tecla);

	}
}

// Actualiza el juego
void Game::update() {
	pac->update();
	
	List<Ghost*>::Iterator it = fantasmas.begin();
	while (it != fantasmas.end())
	{
		it.elem()->update();
		++it;
	}

	if (comida == 0)
	{
		nMapa++;
		CambioMapa();
	}
	
	SDL_Delay(235);
}

void Game::CambioMapa()
{
	delete pac;
	List<Ghost*>::Iterator it = fantasmas.begin();
	while (it != fantasmas.end())
	{
		delete* it;
		++it;
	}
	delete mapa;

	LeeArchivo(nombreNivel(nMapa));
}

// Comprueba la siguiente posicion de la celda teniendo en cuenta su posicion y su direccion
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

// Maneja el juego
void Game::run() {
	SDL_Event event;
	while (!fin() && pac->returnLives() > 0 && nMapa <= 5)
	{
		render();
		handleEvent(event);
		update();
	}
}

Game::~Game()
{
	delete pac;
	
	List<Ghost*>::Iterator it = fantasmas.begin();
	while (it != fantasmas.end())
	{
		delete *it;
		++it;
	}

	for (int i = 0; i < NUM_TEXTURES; ++i)
	{
		delete textures[i];
	}

	delete mapa;

	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	SDL_Quit();
}