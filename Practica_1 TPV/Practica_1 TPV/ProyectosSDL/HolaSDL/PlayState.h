#pragma once
#include "Game.h"
#include "GameState.h"
#include "GameObject.h"
#include "Ghost.h"
#include "SmartGhost.h"
#include "PacMan.h"
#include "GameMap.h"
#include "checkML.h"
#include <list>

class PlayState : public GameState
{
private:

	int tamCellX, tamCellY;
	int comida = 0;
	int nMapa = 1;

	int vidas = 3;
	int puntuacion = 0;

	PacMan* pac;
	GameMap* mapa;
	
	list<SmartGhost*> fantasmas;
	list<list<GameObject*>::iterator> objectstoErase;
public:

	PlayState( Game* g) :GameState(g) {	g->stMachine()->pushState(this);};


	void update();

	string nombreNivel(int nMapa);
	bool LeeArchivo(string archivo);
	void CambioMapa();
	void SaveToFile();

	void render();

	SDL_Point mapCoordsToSDLPoint(Point2D& coords);
	Point2D SDLPointToMapCoords(int x, int y);
	bool trymove(const SDL_Rect rect, Vector2D dir, Point2D newPos, bool g);
	void check();


	void ripFantasma(SmartGhost* Sg);
	bool Hijo(SmartGhost* Sg);
	bool ComprobarDistancia(SmartGhost* Sg, list<SmartGhost*>::iterator it);
	bool Chocar(SDL_Rect Sg1, SDL_Rect Sg2);

	void OnEnter(){ LeeArchivo(nombreNivel(nMapa)); }

	int CellX() { return tamCellX; }
	int CellY() { return tamCellY; }
	void restaVida() { vidas--; }
	void sumaPuntos() { puntuacion += 10; }
	GameMap* getMapa() { return mapa; }
	PacMan* getPac() { return pac; }

	SDL_Rect map() { return mapa->getDestRect(); }
	void restaComida() { comida--; }

	void eraseGhost(list<GameObject*>::iterator it);
	void eraseObject(list<GameObject*>::iterator it);
	~PlayState();


};

