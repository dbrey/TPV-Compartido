
#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

Game::Game(SDL_Window* window, SDL_Renderer* renderer) {
	window_ = window;
	renderer_ = renderer;


	stateMachine = new GameStateMachine();
	stateMachine->pushState(new MainMenuState());
}

void Game::render() {
	SDL_RenderClear(renderer_);
	
	stateMachine->currentState()->render();

	SDL_RenderPresent(renderer_);
}

void Game::run() {
	IniTextures();
	LeeArchivo(nombreNivel(nMapa));
	SDL_Event event;
	while (!fin() && vidas > 0 && nMapa <= 5)
	{
		render();

		stateMachine->currentState()->handleEvent(event);
		stateMachine->currentState()->update();
	}
}

void Game::IniTextures()
{
	try
	{
		for (int i = 0; i < NUM_TEXTURES; ++i)
		{
			textures[i] = new Texture(renderer_, TEXTURE_ATRIBS[i].fileName, TEXTURE_ATRIBS[i].numRows, TEXTURE_ATRIBS[i].numCols);
		}
	}
	catch(string& e)
	{
		throw FileNotFoundError(e);
	}
	
}


// Dependiendo del nivel seleccionado se juega un nivel predeterminado o la partida guardada
//string Game::nombreNivel(int nMapa)
//{
//	cout << "Cargar nivel o empezar partida nueva? (0 o 1) ";
//	int opcion;
//	cin >> opcion;
//	if (opcion == 1)
//	{
//		stringstream nombre;
//		nombre << "../mapas/level0" << nMapa << ".dat";
//		return nombre.str();
//	}
//	else
//	{
//		stringstream nombre;
//		nombre << "../mapas/partida.txt";
//		return nombre.str();
//	}
//}
//
//// Lee el archivo y asigna los elementos del archivo a las variables de Game(PacMan,Ghost,Mapa...)
//bool Game::LeeArchivo(string archivo) {
//	bool read = true;  ifstream input;
//    input.open(archivo);
//
//	if (!input.is_open()) {
//		throw FileNotFoundError(archivo);
//		read = false;
//	}
//	else {
//		try
//		{
//			int x, y;
//			input >> x >> y;
//
//			tamCellY = 600 / x;
//			tamCellX = 800 / y;
//			mapa = new GameMap(x, y, this);
//
//			int aux;
//			for (int i = 0; i < x; i++) {
//				for (int j = 0; j < y; j++) {
//					input >> aux;
//					if (aux == 1)
//						mapa->writeCell(j, i, Wall);
//					else if (aux == 2) {
//						mapa->writeCell(j, i, Food);
//						comida++;
//					}
//					else if (aux == 3)
//						mapa->writeCell(j, i, Vitamins);
//					else {
//						mapa->writeCell(j, i, Empty);
//						if (aux == 9) {
//							pac = new PacMan(mapCoordsToSDLPoint(Point2D(j, i)).x, mapCoordsToSDLPoint(Point2D(j, i)).y, this, Vector2D(1, 0), tamCellX, tamCellY);
//							stateMachine->currentState()-> objects.push_back(pac);
//						}
//						else if ((aux == 5 || aux == 6 || aux == 7 || aux == 8)) {
//							SmartGhost* g = new SmartGhost(mapCoordsToSDLPoint(Point2D(j, i)).x, mapCoordsToSDLPoint(Point2D(j, i)).y, this, Vector2D(1, 0), tamCellX, tamCellY, true);
//							fantasmas.push_back(g);
//							list<GameObject*>::iterator it = objects.insert(objects.end(), g);
//							g->setItList(it);
//
//						}
//					}
//				}
//			}
//
//			objects.push_back(mapa);
//		}
//		catch(string& e)
//		{
//			throw FileFormatError(e);
//		}
//		
//	}
//
//	// Si cargamos un mapa, miramos la posicion de los fantasmas y pacman
//	if (archivo == "../mapas/partida.txt")
//	{
//		int aux;
//
//		input >> vidas >> puntuacion;
//
//		input >> aux;
//
//		for (int i = 0; i < aux; i++)
//		{
//			string aux;
//			input >> aux;
//			if (aux == "p") {
//				// Crear una nueva consrtuctora
//				int x, y, dirx, diry;
//				input >> x >> y >> dirx >> diry;
//
//				Vector2D dir(dirx, diry);
//				pac = new PacMan(Point2D(x, y).getX(), Point2D(x, y).getY(), this, dir, tamCellX, tamCellY);
//				stateMachine.currentState() objects.push_back(pac);
//			}
//			else if (aux == "f") {
//				int x, y, dirx, diry;
//				input >> x >> y >> dirx >> diry;
//
//				Vector2D dir(dirx, diry);
//				SmartGhost* g = new SmartGhost(mapCoordsToSDLPoint(Point2D(x,y)).x, mapCoordsToSDLPoint(Point2D(x, y)).y, this, Vector2D(1, 0), tamCellX, tamCellY, true);
//				fantasmas.push_back(g);
//				list<GameObject*>::iterator it = objects.insert(objects.end(), g);
//				g->setItList(it);
//			}
//			else //Ya solo puede sel el numero del mapa
//			{
//				input >> nMapa;
//			}
//		}
//		}
//		
//
//	input.close();
//	return read;
//}
//
//// Inicializa las texturas del juego
//void Game::IniTextures()
//{
//	try
//	{
//		for (int i = 0; i < NUM_TEXTURES; ++i)
//		{
//			textures[i] = new Texture(renderer_, TEXTURE_ATRIBS[i].fileName, TEXTURE_ATRIBS[i].numRows, TEXTURE_ATRIBS[i].numCols);
//		}
//	}
//	catch(string& e)
//	{
//		throw FileNotFoundError(e);
//	}
//	
//}
//
//// Hace conversion de Coordenadas a SDL Point
//SDL_Point Game::mapCoordsToSDLPoint(Point2D& coords)
//{
//	SDL_Point aux;
//
//	aux.x =coords.getX() * tamCellX;
//	aux.y =coords.getY() * tamCellY;
//	return aux;
//}
//
//// Hace conversion de SDL Point a coordenadas
//Point2D Game::SDLPointToMapCoords(int x, int y)
//{
//	Point2D aux = Point2D((x / tamCellX), (y / tamCellY));
//	return aux;
//}
//
//// Crea el hijo del fantasma si 2 fantasmas entran en colision
//bool Game::Hijo(SmartGhost* Sg)
//{
//	list<SmartGhost*>::iterator it = fantasmas.begin();
//
//	while (it != fantasmas.end()) 
//	{
//		if (Sg != *it && !((*it)->EsHijo()) && ComprobarDistancia(Sg, it))
//		{
//			
//				SmartGhost* g = new SmartGhost(Sg->getPoint().getX(), Sg->getPoint().getY(), this, Vector2D(1, 0), tamCellX, tamCellY, true);
//				fantasmas.push_back(g);
//				list<GameObject*>::iterator it = objects.insert(objects.end(), g);
//				g->setItList(it);
//				return true;
//
//		}
//		it++;
//	}
//	return false;
//}
//
//// Comprueba la distancia entre 2 fantasmas
//bool Game::ComprobarDistancia(SmartGhost* Sg, list<SmartGhost*>::iterator it)
//{
//	return ((Sg->getDestRect().y == (*it)->getDestRect().y &&
//		Sg->getDestRect().x - (*it)->getDestRect().x < 10 &&
//		Sg->getDestRect().x - (*it)->getDestRect().x > -10) &&
//
//		(Sg->getDestRect().x == (*it)->getDestRect().x &&
//			Sg->getDestRect().y - (*it)->getDestRect().y < 10 &&
//			Sg->getDestRect().y - (*it)->getDestRect().y > -10) &&
//
//		Chocar(Sg->getDestRect(), (*it)->getDestRect()));
//}
//
//// Comprueba la colision entre 2 personajes
//bool Game::Chocar(SDL_Rect Sg1, SDL_Rect Sg2)
//{
//	Point2D topLeft1 = SDLPointToMapCoords(Sg1.x, Sg1.y);
//	Point2D botRight1 = SDLPointToMapCoords((Sg1.x + Sg1.w - 1), (Sg1.y + Sg1.h - 1));
//
//	Point2D topLeft2 = SDLPointToMapCoords(Sg2.x, Sg2.y);
//	Point2D botRight2 = SDLPointToMapCoords((Sg2.x + Sg2.w - 1), (Sg2.y + Sg2.h - 1));
//
//	// Comprobamos colision entre 2 personajes
//	for (int c = topLeft1.getX(); c <= botRight1.getX(); c++)
//	{
//		for (int r = topLeft1.getY(); r <= botRight1.getY(); r++)
//		{
//			for (int x = topLeft2.getX(); x <= botRight2.getX(); x++)
//			{
//				for (int y = topLeft2.getY(); y <= botRight2.getY(); y++)
//				{
//					if (c == x || r == y)
//					{
//						return true;
//					}
//				}
//			}
//		}
//	}	
//	return false;
//}
//
//// Renderiza todos los elementos del juego
//
//
//// Actualiza el juego
//void Game::update() {
//	for (GameObject* o : objects)
//	{
//		GameCharacter* c = dynamic_cast<GameCharacter*>(o);
//		if (c != nullptr) { c->update(); }
//	}
//
//	for (auto it : objectstoErase)
//	{
//		delete *it;
//		objects.erase(it);
//	}
//	objectstoErase.clear();
//
//	if (comida == 0)
//	{
//		nMapa++;
//		CambioMapa();
//		
//	}
//	
//	SDL_Delay(10);
//}
//
//// Borra al SmartGhost
//void Game::ripFantasma(SmartGhost* sg)
//{
//	bool aux = false; //Para salir del bucle
//	list<SmartGhost*>::iterator it = fantasmas.begin();
//	while (it != fantasmas.end() && !aux) //Busca el fantasma y lo borra
//	{
//		if (sg == *it)
//		{
//			delete* it;
//			aux = true;
//		}
//		++it;
//	}
//}
//
//// Cambia al siguiente mapa
//void Game::CambioMapa()
//{
//	list<GameObject*>::iterator it = objects.begin();
//	while (it != objects.end())
//	{
//		delete* it;
//		++it;
//	}
//
//	objectstoErase.clear();
//	fantasmas.clear();
//	objects.clear();
//	LeeArchivo(nombreNivel(nMapa));
//}
//
//// Comprueba si puede moverse al siguiente pixel teniendo en cuenta su direccion y posicion
//bool Game::trymove(const SDL_Rect rect, Vector2D dir, Point2D newPos, bool g)
//{
//	if (newPos.getX() + rect.w == 760)
//	{
//		int x = 0;
//	}
//
//	SDL_Rect mapRect = mapa->getDestRect();
//	newPos.Suma(dir.GetX(), dir.GetY());
//	// Comprobamos direccion y averiguamos si nos salimos del mapa
//	// Derecha
//	if ((dir.GetX() > 0 && (newPos.getX() + rect.w) >= mapRect.x + mapRect.w))
//		newPos.SetPos(0, newPos.getY());
//
//	//Izquierda
//	else if (dir.GetX() < 0 && (newPos.getX()) <= 0)
//		newPos.SetPos(mapRect.x + mapRect.w - rect.x, newPos.getY()); //10 = rect.w del pacman
//
//	// Arriba
//	else if (dir.GetY() < 0 && (newPos.getY()) <= 0)
//		newPos.SetPos(newPos.getX(), mapRect.y + mapRect.h - rect.y);
//
//	// Abajo
//	else if (dir.GetY() > 0 && (newPos.getY() + rect.h) > mapRect.y + mapRect.h)
//		newPos.SetPos(newPos.getX(), 0);
//
//	SDL_Rect newRect = { newPos.getX(), newPos.getY(), rect.w, rect.h };
//	return !(mapa->intersectsWall(newRect, g));
//
//}
//
//// Guarda la partida
//void Game::SaveToFile()
//{
//	ofstream fil;
//	fil.open("../mapas/partida.txt");
//
//	if (!fil.is_open())
//	{
//		string aux = "../mapas/partida.txt";
//		throw FileNotFoundError(aux);
//	}
//	else
//	{
//		fil << mapa->cols << " " << mapa->fils << endl;
//
//		for (int j = 0; j < mapa->cols; j++)
//		{
//			for (int i = 0; i < mapa->fils; i++)
//			{
//				if (mapa->readCell(i, j) == Wall)
//				{
//					fil << "1 ";
//				}
//				else if (mapa->readCell(i, j) == Food)
//				{
//					fil << "2 ";
//				}
//				else if (mapa->readCell(i, j) == Vitamins)
//				{
//					fil << "3 ";
//				}
//				else if (mapa->readCell(i, j) == Empty)
//				{
//					fil << "0 ";
//				}
//			}
//			fil << endl;
//		}
//
//		fil << vidas << " " << puntuacion << endl;
//		fil << objects.size() << endl;
//
//		for (GameObject* o : objects)
//		{
//			GameCharacter* c = dynamic_cast<GameCharacter*>(o);
//			if (c != nullptr) c->saveToFil(fil);
//		}
//
//		fil << endl;
//		fil << nMapa;
//
//		exit = true; //Cerrar el bucle del juego
//
//		fil.close();
//	}
//
//	
//}
//
//// Maneja el juego
//
//
//// Comprueba si PacMan esta en la misma posicion que algun fantasma y uno de los 2 muere
//void Game::check() {
//	for (Ghost* g : fantasmas)
//	{
//		SDL_Rect rectg = g->getDestRect();
//		if (SDL_HasIntersection(&rectg, &pac->getDestRect()))
//		{
//			if (pac->tiempo() == 0) {
//				pac->morir();
//			}
//			else {
//				g->morir();
//			}
//		}
//	}
//}
//
//// Se deshace del fantasma y lo deja pendiente para borrar completamente
//void Game::eraseGhost(list<GameObject*>::iterator it)
//{
//	GameObject* go = *it;
//	SmartGhost* g = dynamic_cast<SmartGhost*>(go);
//	fantasmas.remove(g);
//	eraseObject(it);
//}
//
////Se deshace del objeto y lo deja pendiente para borrar completamente
//void Game::eraseObject(list<GameObject*>::iterator it)
//{
//	objectstoErase.push_back(it);
//}

Game::~Game()
{
	delete stateMachine;

	for (int i = 0; i < NUM_TEXTURES; ++i)
	{
		delete textures[i];
	}

	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	SDL_Quit();
}