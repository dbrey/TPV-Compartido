#include "PlayState.h"
#include "checkML.h"

// Si empezamos desde una partida nueva
PlayState::PlayState(Game* g) : GameState(g)
{
	LeeArchivo(nombreNivel(nMapa));
};

// Si empezamos desde una partida guardada
PlayState::PlayState(Game* g, string name) : GameState(g)
{
	LeeArchivo(name);
}

// Va al menu de Pausa
void PlayState::pausar()
{
	PauseState* pausa = new PauseState(g);
	g->stMachine()->pushState(pausa);
	
}


void PlayState::update()
{
	GameState::update();

	for (auto it : objectstoErase)
	{
		delete* it;
		stage.erase(it);
	}
	objectstoErase.clear();


	if (comida == 0)
	{
		nMapa++;
		if (nMapa <= 5)
		{
			CambioMapa();
		}
	}


	if (nMapa > 5 || vidas == 0)
	{
		
		EndState* ending;
		if (nMapa > 5)
		{
			ending = new EndState(g, true);
		}
		else
		{
			ending = new EndState(g, false);
		}

		g->stMachine()->pushState(ending);

	}
	SDL_Delay(10);

}

// Creamos un string con el numero del nivel
string PlayState::nombreNivel(int nMapa)
{
		stringstream nombre;
		nombre << "../mapas/level0" << nMapa << ".dat";
		return nombre.str();
}

// Leemos el contenido del archivo y creamos el juego a partir de ahi
bool PlayState::LeeArchivo(string archivo) {
	bool read = true;  ifstream input;
	input.open(archivo);

	if (!input.is_open()) {
		throw FileNotFoundError(archivo);
		read = false;
	}
	else {
			int x, y;
			input >> x >> y;

			tamCellY = 600 / x;
			tamCellX = 800 / y;
			mapa = new GameMap(x, y, g , tamCellX,tamCellY);

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
							pac = new PacMan(mapCoordsToSDLPoint(Point2D(j, i)).x, mapCoordsToSDLPoint(Point2D(j, i)).y, g, this, Vector2D(1, 0), tamCellX, tamCellY);
							stage.push_back(pac);
							manejadores.push_back(pac);
						}
						else if ( aux == 4) {
							SmartGhost* smgh = new SmartGhost(mapCoordsToSDLPoint(Point2D(j, i)).x, mapCoordsToSDLPoint(Point2D(j, i)).y, g, this, Vector2D(1, 0), tamCellX, tamCellY, true);
							SmartFantasmas.push_back(smgh);
							list<GameObject*>::iterator it = stage.insert(stage.end(), smgh);
							smgh->setItList(it);

						}
						else if ((aux == 5 || aux == 6 || aux == 7 || aux == 8))
						{
							Ghost* ngh = new Ghost(mapCoordsToSDLPoint(Point2D(j, i)).x, mapCoordsToSDLPoint(Point2D(j, i)).y, g, this, Vector2D(1, 0), tamCellX, tamCellY, aux);
							normalFantasmas.push_back(ngh);
							list<GameObject*>::iterator it = stage.insert(stage.end(), ngh);
							ngh->setItList(it);
						}
					}
				}
			}

			stage.push_back(mapa);
	}

	// Si cargamos un mapa, miramos la posicion de los fantasmas y pacman
	if (archivo == "../mapas/partida.txt" || archivo == "../mapas/partida2.txt" || archivo == "../mapas/partida3.txt")
	{
		int aux;

		input >> vidas >> puntuacion;

		input >> aux;

		for (int i = 0; i < aux; i++)
		{
			string aux;
			input >> aux;
			if (aux == "p") {
				// Crear una nueva consrtuctora
				int x, y, dirx, diry;
				input >> x >> y >> dirx >> diry;

				Vector2D dir(dirx, diry);
				pac = new PacMan(Point2D(x, y).getX(), Point2D(x, y).getY(), g, this, dir, tamCellX, tamCellY);
				stage.push_back(pac);
				manejadores.push_back(pac);
			}
			else if (aux == "f") {
				int x, y, dirx, diry;
				input >> x >> y >> dirx >> diry;

				Vector2D dir(dirx, diry);
				SmartGhost* smghost = new SmartGhost(Point2D(x, y).getX(), Point2D(x, y).getY(), g, this, Vector2D(1, 0), tamCellX, tamCellY, true);
				SmartFantasmas.push_back(smghost);
				list<GameObject*>::iterator it = stage.insert(stage.end(), smghost);
				smghost->setItList(it);
			}
			else if ((aux == "5" || aux == "6" || aux == "7" || aux == "8"))
			{
				int x, y, dirx, diry;
				input >> x >> y >> dirx >> diry;
				
				Ghost* nghost = new Ghost(Point2D(x, y).getX(), Point2D(x, y).getY(), g, this, Vector2D(1, 0), tamCellX, tamCellY, stoi(aux));
				normalFantasmas.push_back(nghost);
				list<GameObject*>::iterator it = stage.insert(stage.end(), nghost);
				nghost->setItList(it);
			}
			else//Ya solo puede sel el numero del mapa
			{
				input >> nMapa;
				if (nMapa > 5) throw FileFormatError("The map number"+ to_string(nMapa) + "dont exist");
			}
		}
	}


	input.close();
	return read;
}

// Avanza al siguiente nivel
void PlayState::CambioMapa()
{
	list<GameObject*>::iterator it = stage.begin();
	while (it != stage.end())
	{
		delete* it;
		++it;
	}

	objectstoErase.clear();
	SmartFantasmas.clear();
	stage.clear();
	LeeArchivo(nombreNivel(nMapa));
}

// Guardamos la partida en el archivo que queramos
void PlayState::SaveToFile()
{
	ofstream fil;

	cout << "Elige un archivo 1,2 o 3 ";
	int eleccion;
	
	cin >> eleccion;

	if (eleccion == 1)
	{
		fil.open("../mapas/partida.txt");

	}
	else if(eleccion == 2)
	{
		fil.open("../mapas/partida2.txt");

	}
	else if (eleccion == 3)
	{
		fil.open("../mapas/partida3.txt");

	}
	

	if (!fil.is_open())
	{
		string aux = "../mapas/partida.txt";
		throw FileNotFoundError(aux);
	}
	else
	{
		fil << mapa->c() << " " << mapa->fil() << endl;

		for (int j = 0; j < mapa->c(); j++)
		{
			for (int i = 0; i < mapa->fil(); i++)
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

		fil << vidas << " " << puntuacion << endl;
		fil << stage.size() << endl;

		for (GameObject* o : stage)
		{
			GameCharacter* c = dynamic_cast<GameCharacter*>(o);
			if (c != nullptr) c->saveToFil(fil);
		}

		fil << endl;
		fil << nMapa;

		g->terminar(); //Cerrar el bucle del juego

		fil.close();
	}


}

// Hace conversion de las coordenadas del mapa a SDLPoint
SDL_Point PlayState::mapCoordsToSDLPoint(Point2D& coords)
{
	SDL_Point aux;

	aux.x = coords.getX() * tamCellX;
	aux.y = coords.getY() * tamCellY;
	return aux;
}

// Hace conversion de SDL Point a coordenadas
Point2D PlayState::SDLPointToMapCoords(int x, int y)
{
	Point2D aux = Point2D((x / tamCellX), (y / tamCellY));
	return aux;
}

bool PlayState::trymove(const SDL_Rect rect, Vector2D dir, Point2D newPos, bool g)
{
	if (newPos.getX() + rect.w == 760)
	{
		int x = 0;
	}

	SDL_Rect mapRect = mapa->getDestRect();
	newPos.Suma(dir.GetX(), dir.GetY());
	// Comprobamos direccion y averiguamos si nos salimos del mapa
	// Derecha
	if ((dir.GetX() > 0 && (newPos.getX() + rect.w) >= mapRect.x + mapRect.w))
		newPos.SetPos(0, newPos.getY());

	//Izquierda
	else if (dir.GetX() < 0 && (newPos.getX()) <= 0)
		newPos.SetPos(mapRect.x + mapRect.w - rect.x, newPos.getY()); //10 = rect.w del pacman

	// Arriba
	else if (dir.GetY() < 0 && (newPos.getY()) <= 0)
		newPos.SetPos(newPos.getX(), mapRect.y + mapRect.h - rect.y);

	// Abajo
	else if (dir.GetY() > 0 && (newPos.getY() + rect.h) > mapRect.y + mapRect.h)
		newPos.SetPos(newPos.getX(), 0);

	SDL_Rect newRect = { newPos.getX(), newPos.getY(), rect.w, rect.h };
	return !(mapa->intersectsWall(newRect, g));

}

// Chequeamos si hay colision entre pacman y algun fantasma
void PlayState::check() {
	for (Ghost* g : SmartFantasmas)
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

void PlayState::ripFantasma(SmartGhost* sg)
{
	bool aux = false; //Para salir del bucle
	list<SmartGhost*>::iterator it = SmartFantasmas.begin();
	while (it != SmartFantasmas.end() && !aux) //Busca el fantasma y lo borra
	{
		if (sg == *it)
		{
			delete* it;
			aux = true;
		}
		++it;
	}
}

bool PlayState::Hijo(SmartGhost* Sg)
{
	list<SmartGhost*>::iterator it = SmartFantasmas.begin();

	while (it != SmartFantasmas.end())
	{
		if (Sg != *it && !((*it)->EsHijo()) && ComprobarDistancia(Sg, it) && !((*it)->Papa()))
		{
			// Es probable que gh este dando error
			SmartGhost* gh = new SmartGhost(Sg->getPoint().getX(), Sg->getPoint().getY(), g, this, Vector2D(1, 0), tamCellX, tamCellY, true);
			SmartFantasmas.push_back(gh);
			list<GameObject*>::iterator it = stage.insert(stage.end(), gh);
			gh->setItList(it);
			return true;

		}
		it++;
	}
	return false;
}

bool PlayState::ComprobarDistancia(SmartGhost* Sg, list<SmartGhost*>::iterator it)
{
	return ((Sg->getDestRect().y == (*it)->getDestRect().y &&
		Sg->getDestRect().x - (*it)->getDestRect().x < 10 &&
		Sg->getDestRect().x - (*it)->getDestRect().x > -10) &&

		(Sg->getDestRect().x == (*it)->getDestRect().x &&
			Sg->getDestRect().y - (*it)->getDestRect().y < 10 &&
			Sg->getDestRect().y - (*it)->getDestRect().y > -10) &&

		Chocar(Sg->getDestRect(), (*it)->getDestRect()));
}

bool PlayState::Chocar(SDL_Rect Sg1, SDL_Rect Sg2)
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

// Se deshace del fantasma y lo deja pendiente para borrar completamente
void PlayState::eraseGhost(list<GameObject*>::iterator it)
{
	GameObject* go = *it;
	SmartGhost* g = dynamic_cast<SmartGhost*>(go);
	SmartFantasmas.remove(g);
	eraseObject(it);
}

//Se deshace del objeto y lo deja pendiente para borrar completamente
void PlayState::eraseObject(list<GameObject*>::iterator it)
{
	objectstoErase.push_back(it);
}

PlayState::~PlayState()
{
	for (auto objeto : stage)
	{
		GameCharacter* aux = dynamic_cast<GameCharacter*>(objeto);
		if (objeto != nullptr)
		{
			delete[] objeto;
		}
	}

	delete[] mapa;
	objectstoErase.clear();
	SmartFantasmas.clear();
	stage.clear();
}

