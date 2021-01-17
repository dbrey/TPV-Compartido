
#include "PacMan.h"


PacMan::PacMan(int x, int y, Game* g, PlayState* pl, Vector2D dir, int ancho, int largo) : GameCharacter(Point2D(x, y), dir, g->getTexture(characters), g, pl, largo, ancho) {}


// Lee la celda en la que se encuentra PacMan y si hay algo comestible, lo come y lo deja vacio
void PacMan::comida() {
	if (play->getMapa()->readCell(play->SDLPointToMapCoords(point.getX(), point.getY()).getX(), play->SDLPointToMapCoords(point.getX(), point.getY()).getY()) == Food)
	{
		play->getMapa()->writeCell(play->SDLPointToMapCoords(point.getX(), point.getY()).getX(), play->SDLPointToMapCoords(point.getX(), point.getY()).getY(), Empty);
		play->restaComida();
		play->sumaPuntos();
	}
	else if (play->getMapa()->readCell(play->SDLPointToMapCoords(point.getX(), point.getY()).getX(), play->SDLPointToMapCoords(point.getX(), point.getY()).getY()) == Vitamins)
	{
		play->getMapa()->writeCell(play->SDLPointToMapCoords(point.getX(), point.getY()).getX(), play->SDLPointToMapCoords(point.getX(), point.getY()).getY(), Empty);
		tiempoforce = duracion;
	}
}

// Recoge el input y establece la direccion a tomar
bool PacMan::handleEvent(SDL_Event& tecla)
{
	if (tecla.type == SDL_KEYDOWN)
	{
		switch (tecla.key.keysym.sym)
		{
			case SDLK_LEFT:
			{
				dir_sel.setdir(-1, 0);
				return true;
			}
			case SDLK_RIGHT:
			{
				dir_sel.setdir(1, 0);
				return true;
			}
			case SDLK_UP:
			{
				dir_sel.setdir(0, -1);
				return true;
			}
			case SDLK_DOWN:
			{
				dir_sel.setdir(0, 1);
				return true;
			}
			case SDLK_s:
			{
				play->SaveToFile();
			}
			default:
			{
				return false;
			}
		}
	}
}

// Chequeamos la posicion del pacman y ejecutamos las acciones necesarias
void PacMan::update() {
	play->check();
	comida();

	// En el momento que aparezca otro camino y la direccion seleccionada sea uno de esos caminos, cambiamos la direccion
	if (play->trymove(getDestRect(),dir_sel, point,false)) //Me puedo mover en la direccion seleccionada
	{ 
		dir_actual = dir_sel;

		SDL_Rect mapRect = play->map();
		Move(point, dir_actual,mapRect);
	}
	else if (play->trymove(getDestRect(), dir_actual, point,false)) //Me puedo mover en la direccion actual
	{
		SDL_Rect mapRect = play->map();
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
	play->restaVida();
	point = iniPoint;
}

// Renderizamos a PacMan
void PacMan::render() {
	SDL_Rect rect;
	rect.x = point.getX();
	rect.y = point.getY();
	rect.w = play->CellX();
	rect.h = play->CellY();
	
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