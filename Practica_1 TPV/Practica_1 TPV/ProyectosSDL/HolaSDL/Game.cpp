
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
}

string Game::nombreNivel(int nMapa)
{
	cout << "Cargar nivel o empezar partida nueva? (0 o 1) ";
	int opcion;
	cin >> opcion;
	if (opcion == 1)
	{
		stringstream nombre;
		nombre << "../mapas/level0" << nMapa << ".dat";
		return nombre.str();
	}
	else
	{
		stringstream nombre;
		nombre << "../mapas/partida.txt";
		return nombre.str();
	}
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

		tamCellY = 600 /x;
		tamCellX = 800 /y;
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
					if (aux == 9) {
						pac = new PacMan(mapCoordsToSDLPoint(Point2D(j, i)).x, mapCoordsToSDLPoint(Point2D(j, i)).y, this, Vector2D(1, 0),tamCellX,tamCellY);
						objects.push_back(pac);
					}
					else if ((aux == 5 || aux == 6 || aux == 7 || aux == 8)) {
						
						fantasmas.push_back(new Ghost(mapCoordsToSDLPoint(Point2D(j, i)).x, mapCoordsToSDLPoint(Point2D(j, i)).y, this, Vector2D(1, 0), tamCellX, tamCellY));
						objects.push_back(fantasmas.back());
					}
				}
			}
		}
		
		objects.push_back(mapa);
	}

	if (archivo == "../mapas/partida.txt")
	{
		string aux;


		if (aux == "p") {
			int x, y, dirx, diry;
			cin >> x >> y >> dirx >> diry;

			Vector2D dir(dirx, diry);
			pac = new PacMan(Point2D(x,y).getX(), Point2D(x,y).getY(), this, dir, tamCellX, tamCellY);
			objects.push_back(pac);
		}
		else if (aux == "f") {
			int x, y, dirx, diry;
			cin >> x >> y >> dirx >> diry;

			Vector2D dir(dirx, diry);
			fantasmas.push_back(new Ghost(Point2D(x, y).getX(), Point2D(x, y).getY(), this,dir, tamCellX, tamCellY));
			objects.push_back(fantasmas.back());
		}
		else //Ya solo puede sel el numero del mapa
		{
			cin >> nMapa;
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

SDL_Point Game::mapCoordsToSDLPoint(Point2D& coords)
{
	SDL_Point aux;

	aux.x =coords.getX() * tamCellX;
	aux.y =coords.getY() * tamCellY;
	return aux;
}

Point2D Game::SDLPointToMapCoords(int x, int y)
{
	Point2D aux = Point2D((x / tamCellX), (y / tamCellY));
	return aux;
}

bool Game::Hijo(SmartGhost* Sg)
{
	list<Ghost*>::iterator it = fantasmas.begin();


	while (it != fantasmas.end())
	{
		if (Sg != *it && Chocar(Sg->getDestRect(), (*it)->getDestRect()))
		{
			fantasmas.push_back(new SmartGhost(Sg->getPoint().getX(), Sg->getPoint().getY(), this, Vector2D(1,0), tamCellX, tamCellY, false));
			objects.push_back(fantasmas.back());
			return true;
		}
		it++;
	}
	return false;
}

bool Game::Chocar(SDL_Rect Sg1, SDL_Rect Sg2)
{
	Point2D topLeft1 = SDLPointToMapCoords(Sg1.x, Sg1.y);
	Point2D botRight1 = SDLPointToMapCoords((Sg1.x + Sg1.w - 1), (Sg1.y + Sg1.h - 1));

	Point2D topLeft2 = SDLPointToMapCoords(Sg2.x, Sg2.y);
	Point2D botRight2 = SDLPointToMapCoords((Sg2.x + Sg2.w - 1), (Sg2.y + Sg2.h - 1));

	// Comprobamos colision entre 2 personajes
	for (int c = topLeft1.getX(); c <= botRight1.getX(); c++)
	{
		for (int r = topLeft1.getY(); r <= botRight1.getY(); r++)
		{
			for (int x = topLeft2.getX(); x <= botRight2.getX(); x++)
			{
				for (int y = topLeft2.getY(); y <= botRight2.getY(); y++)
				{
					if (c == x || r == y)
					{
						return true;
					}
				}
			}
		}
	}	
	return false;
}

Ghost* Game::getGhost(int i)
{
	int aux = 0;
	list<Ghost*>::iterator it = fantasmas.begin();
	while (it != fantasmas.end() && aux != i)
	{
		aux++;
		++it;
	}

	return *it;
}

// Renderiza todos los elementos del juego
void Game::render() {
	SDL_RenderClear(renderer_);
	mapa->render();
	
	for (auto i : objects) {
		i->render();
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
	for (GameObject* o : objects)
	{
		GameCharacter* c = dynamic_cast<GameCharacter*>(o);
		if (c != nullptr) { c->update(); }
	}

	if (comida == 0)
	{
		nMapa++;
		CambioMapa();
	}
	
	SDL_Delay(10);
}

void Game::ripFantasma(SmartGhost* sg)
{
	bool aux = false; //Para salir del bucle
	list<Ghost*>::iterator it = fantasmas.begin();
	while (it != fantasmas.end() && !aux) //Busca el fantasma y lo borra
	{
		if (sg == *it)
		{
			delete* it;
			aux = true;
		}
		++it;
	}
}

void Game::CambioMapa()
{
	delete pac;
	list<Ghost*>::iterator it = fantasmas.begin();
	while (it != fantasmas.end())
	{
		delete* it;
		++it;
	}
	delete mapa;

	LeeArchivo(nombreNivel(nMapa));
}

/*bool Game::tryMove(const SDL_Rect rect, Vector2D dir, Point2D& newPos)
{
	SDL_Rect mapRect = mapa->getDestRect();
	newPos.Suma(dir.GetX()*6, dir.GetY()*6);

	// Comprobamos direccion y averiguamos si nos salimos del mapa
	// Derecha
	if (dir.GetX() > 0 && (newPos.getX() + rect.w) > mapRect.x + mapRect.w)
		newPos.SetPos(mapRect.x, newPos.getY());

	//Izquierda
	else if (dir.GetX() < 0 && (newPos.getX() + rect.w) <= 0)
		newPos.SetPos(mapRect.x + mapRect.w - rect.x, newPos.getY());

	// Arriba
	else if (dir.GetY() < 0 && (newPos.getY() + rect.h) <= 0)
		newPos.SetPos(newPos.getX(), mapRect.y + mapRect.h - rect.y);

	// Abajo
	else if (dir.GetY() > 0 && (newPos.getY() + rect.h) >= mapRect.y + mapRect.y)
		newPos.SetPos(newPos.getX(), mapRect.y);

	SDL_Rect newRect = { newPos.getX(), newPos.getY(), rect.w, rect.h };
	return (mapa->intersectsWall(newRect));

}*/

bool Game::trymove(const SDL_Rect rect, Vector2D dir, Point2D newPos)
{
	SDL_Rect mapRect = mapa->getDestRect();
	newPos.Suma(dir.GetX(), dir.GetY());
	// Comprobamos direccion y averiguamos si nos salimos del mapa

	// Derecha
	if (dir.GetX() > 0 && (newPos.getX() + rect.w) >= mapRect.x + mapRect.w)
		newPos.SetPos(0, newPos.getY());

	//Izquierda
	else if (dir.GetX() < 0 && (newPos.getX()) <= 0)
		newPos.SetPos(mapRect.x + mapRect.w - rect.x, newPos.getY()); //10 = rect.w del pacman

	// Arriba
	else if (dir.GetY() < 0 && (newPos.getY()) <= 0)
		newPos.SetPos(newPos.getX(), mapRect.y + mapRect.h - rect.y);

	// Abajo
	else if (dir.GetY() > 0 && (newPos.getY() + rect.h) >= mapRect.y + mapRect.h)
		newPos.SetPos(newPos.getX(), 0);

	SDL_Rect newRect = { newPos.getX(), newPos.getY(), rect.w, rect.h };
	return !(mapa->intersectsWall(newRect));

}
// Comprueba la siguiente posicion de la celda teniendo en cuenta su posicion y su direccion
//  bool Game::nextCell(Vector2D dir, Point2D pos)
//{
//	if (dir.GetX() == -1) {
//		return	(getMapa()->readCell(pos.getX() - 1, pos.getY()) != Wall);
//	}
//	else if (dir.GetX() == 1) {
//		return (getMapa()->readCell(pos.getX() + 1, pos.getY()) != Wall);
//	}
//	else if (dir.GetY() == -1) {
//		return getMapa()->readCell(pos.getX(), pos.getY() - 1) != Wall;
//	}
//	else if (dir.GetY() == 1) {
//		return (getMapa()->readCell(pos.getX(), pos.getY() + 1) != Wall);
//	}
//
//}

void Game::SaveToFile()
{
	ofstream fil;
	fil.open("../mapas/partida.txt");

	for (int j = 0; j < mapa->cols; j++)
	{
		for (int i = 0; i<mapa->fils;i++)
		{
			if (mapa->readCell(i, j) == Wall)
			{
				fil << "1 ";
			}
			else if (mapa->readCell(i, j) == Food)
			{
				fil << "2 ";
			}
			else if (mapa->readCell(i, j) == Vitamins)
			{
				fil << "3 ";
			}
			else if (mapa->readCell(i, j) == Empty)
			{
				fil << "0 ";
			}
		}
		fil << endl;
	}

	for (GameObject* o : objects)
	{
		GameCharacter* c = dynamic_cast<GameCharacter*>(o);
		if (c != nullptr) c->saveToFil(fil);
	}

	fil << endl;
	fil << nMapa;

	exit = true; //Cerrar el bucle del juego

	fil.close();
}

// Maneja el juego
void Game::run() {
	IniTextures();
	LeeArchivo(nombreNivel(nMapa));
	SDL_Event event;
	while (!fin() && pac->returnLives() > 0 && nMapa <= 5)
	{
		render();
		handleEvent(event);
		update();
	}
}

// Comprueba si PacMan esta en la misma posicion que algun fantasma y uno de los 2 muere
void Game::check() {
	for (Ghost* g : fantasmas)
	{
		SDL_Rect rectg = g->getDestRect();
		if (SDL_HasIntersection(&rectg, &pac->getDestRect()))
		{
			if (pac->tiempo() == 0) {
				pac->morir();
			}
			else {
				g->morir();
			}
		}
	}
}

Game::~Game()
{
	list<GameObject*>::iterator it = objects.begin();
	while (it != objects.end())
	{
		delete *it;
		++it;
	}

	for (int i = 0; i < NUM_TEXTURES; ++i)
	{
		delete textures[i];
	}

	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	SDL_Quit();
}