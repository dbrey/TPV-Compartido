#include "SmartGhost.h"
#include "PlayState.h"

// Llama al update de Ghost o al de SmartGhost
void SmartGhost::update()
{
	if (cuarentena == 0)
	{
		cuarentena = 2000;
	}
	if (edad < edadrip)
	{
		Movimiento();
	}
	if (cuarentena == 2000 && play->Hijo(this) && !EsHijo()) //Comprobamos si esta en cuarentena o no
	{
		cuarentena--;
	}
	else if (cuarentena < 2000)
	{
		cuarentena--;
	}
	if (edad == edadout) //Llamar  metodo para borarr el fantasma
	{
		play->eraseGhost(it);
	}
	edad++;
}

// Se mueve de forma especial para el SmartGhost
void SmartGhost::Mueve()
{
	Point2D pac(0, 0);
	pac = play->getPac()->getPoint();
	if (mov[0] && point.getX() > pac.getX() && !play->getPac()->invencible()) // left
	{
		dir_actual = Vector2D(-1, 0);
		Move(point, dir_actual, play->map());;
	}
	else if (mov[1] && point.getX() > pac.getX() && !play->getPac()->invencible()) // up
	{
		dir_actual = Vector2D(0, -1);
		Move(point, dir_actual, play->map());
	}
	else if (mov[2] && point.getX() < pac.getX() && !play->getPac()->invencible()) // right
	{
		dir_actual = Vector2D(1, 0);
		Move(point, dir_actual, play->map());
	}
	else if (mov[3] && point.getX() < pac.getX()&& !play->getPac()->invencible())// down
	{
		dir_actual = Vector2D(0, 1);
		Move(point, dir_actual, play->map());
	}
	else//random
	{
		vector<int> sel(4);
		for (int cont = 0; cont < 4; cont++) { sel[cont] = cont; }

		int aux = rand() % 4, i = 0;
		while (!mov[aux] && i < 4) {
			// Si la direccion seleccionada esta bloqueada, se descarta
		   if (!mov[aux]) {
				int aux2 = 0;
				while (sel[aux2] != aux && aux2 < 4) // Se meteria en este bucle y no saldria
					aux2++;
				sel[aux2] = -1;
			}
			// Escogemos una nueva direccion posible
			aux = rand() % 4;
			while (sel[aux] == -1)
				aux = rand() % 4;
			i++;
		}

		if (mov[aux]) {
			switch (aux) {
			case 0: {
				dir_actual.setdir(1, 0); // derecha
				break;
			}
			case 1: {
				dir_actual.setdir(-1, 0); // izquierda
				break;
			}
			case 2: {
				dir_actual.setdir(0, -1); // arriba
				break;
			}
			case 3: {
				dir_actual.setdir(0, 1); // abajo
				break;
			}
			}
		}
	}
}

// Movemos al fantasma de forma random o con una direccion preferente
void SmartGhost::Movimiento()
{
	Point2D pac(0,0);
	pac = play->getPac()->getPoint();
	if (((edad < 1000) || (point.getX() > pac.getX() + 100 || point.getX() < pac.getX() + 100 || //Condiciones de cercania
		point.getY() > pac.getY() + 100 || point.getY() < pac.getY() + 100)))
	{
		// Movimiento random
		if (CambMove >= 70 || !play->trymove(getDestRect(), dir_actual, point,true))
		{
			SelecMov();
			CambMove = 0;
		}

		if (play->trymove(getDestRect(), dir_actual, point,true))
		{
			SDL_Rect mapRect = play->map();
			Move(point, dir_actual, mapRect);

		}

		CambMove++;
	}
	else if(edad<edadrip)//Movimiento inteligente
	{
		CheckMov(); //Comprobamos las direcciones a las que puede ir
		Mueve();
	}
}

// Renderiza al fantasma
void SmartGhost::render()
{
	SDL_Rect rect;
	rect.x = point.getX();
	rect.y = point.getY();
	if (edad < 1000)
	{
		rect.w = play->CellX() / 2;
		rect.h = play->CellY() / 2;
	}
	else
	{
		rect.w = play->CellX();
		rect.h = play->CellY();
	}

	if (textura == NULL)
	{
		string aux = "textura SmartGhost";
		throw FileNotFoundError(aux);
	}

	if (edad > edadrip)
	{
		textura->renderFrame(rect, 0, 7);
	}
	else
	{
		textura->renderFrame(rect, 0, 8);
	}

}