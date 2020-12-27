
#include "PacMan.h"
#include "Vector2D.h"
#include "Texture.h"
#include "Game.h"
#include "GameMap.h"
#include <fstream>

PacMan::PacMan(int x, int y, Game* g, Vector2D dir, int ancho, int largo) : GameCharacter(Point2D(x, y),dir, g->getTexture(characters), g, largo, ancho) {

}


// Lee la celda en la que se encuentra PacMan y si hay algo comestible, lo come y lo deja vacio
void PacMan::comida() {
	if (game->getMapa()->readCell(game->SDLPointToMapCoords(point.getX(), point.getY()).getX(), game->SDLPointToMapCoords(point.getX(), point.getY()).getY()) == Food)
	{
		game->getMapa()->writeCell(game->SDLPointToMapCoords(point.getX(), point.getY()).getX(), game->SDLPointToMapCoords(point.getX(), point.getY()).getY(), Empty);
		game->restaComida();
		game->sumaPuntos();
	}
	else if (game->getMapa()->readCell(game->SDLPointToMapCoords(point.getX(), point.getY()).getX(), game->SDLPointToMapCoords(point.getX(), point.getY()).getY()) == Vitamins)
	{
		game->getMapa()->writeCell(game->SDLPointToMapCoords(point.getX(), point.getY()).getX(), game->SDLPointToMapCoords(point.getX(), point.getY()).getY(), Empty);
		tiempoforce = duracion;
	}
}

// Recoge el input y establece la direccion a tomar
void PacMan::handleEvent(SDL_Event& tecla)
{
	if (tecla.type == SDL_KEYDOWN)
	{
		switch (tecla.key.keysym.sym)
		{
			case SDLK_LEFT:
			{
				dir_sel.setdir(-1, 0);
				break;
			}
			case SDLK_RIGHT:
			{
				dir_sel.setdir(1, 0);
				break;
			}
			case SDLK_UP:
			{
				dir_sel.setdir(0, -1);
				break;
			}
			case SDLK_DOWN:
			{
				dir_sel.setdir(0, 1);
				break;
			}
			case SDLK_s:
			{
				game->SaveToFile();
			}
		}
	}
}

// Chequeamos la posicion del pacman y ejecutamos las acciones necesarias
void PacMan::update() {
	game->check();
	comida();

	// En el momento que aparezca otro camino y la direccion seleccionada sea uno de esos caminos, cambiamos la direccion
	if (game->trymove(getDestRect(),dir_sel, point,false)) //Me puedo mover en la direccion seleccionada
	{ 
		dir_actual = dir_sel;

		SDL_Rect mapRect = game->map();
		Move(point, dir_actual,mapRect);
	}
	else if (game->trymove(getDestRect(), dir_actual, point,false)) //Me puedo mover en la direccion actual
	{
		SDL_Rect mapRect = game->map();
		Move(point, dir_actual, mapRect);
	}

	// Si su poder esta activo, reducimos el tiempo
	if (tiempoforce > 0) {
		tiempoforce--;
	}
}

// Lleva a Pacman al punto de spawn y le quita una vida
void PacMan::morir()
{
	game->restaVida();
	point = iniPoint;
}

// Renderizamos a PacMan
void PacMan::render() {
	SDL_Rect rect;
	rect.x = point.getX();
	rect.y = point.getY();
	rect.w = game->CellX();
	rect.h = game->CellY();
	
	// Dependiendo si PacMan tiene el poder activo, le cambiamos el sprite
	if (textura == NULL)
	{
		string aux = "textura pacman";
		throw FileNotFoundError(aux);
	}
	if (tiempoforce == 0)
		textura->renderFrame(rect, 0, 10);
	else
		textura->renderFrame(rect, 0, 11);
	
}

// Guardamos a pacman en el fichero
void PacMan::saveToFil(ofstream& fil)
{
	fil << "p " << point.getX() << " " << point.getY() << " "
		<< dir_actual.GetX() << " " << dir_actual.GetY() << endl;
}

PacMan::~PacMan()
{

}