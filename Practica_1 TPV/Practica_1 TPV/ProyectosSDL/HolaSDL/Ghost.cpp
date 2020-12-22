
#include "Ghost.h"
#include "Vector2D.h"
#include "Texture.h"
#include "Game.h"
#include <fstream>
#include <vector>
#include <cstdlib>


Ghost::Ghost(int x, int y, Game* g, Vector2D dir,int ancho,int largo) : GameCharacter(Point2D(x, y), dir, g->getTexture(characters), g,ancho,largo) {

}

// Comprobamos las direcciones a las que se puede mover el fantasma
void Ghost::CheckMov() //Comprobar que se puede mover en x direccion
{
    Vector2D derecha(1, 0), izquierda(-1, 0), arriba(0, -1), abajo(0, 1);

    mov[0] = game->trymove(getDestRect(),derecha, point, true);
    mov[1] = game->trymove(getDestRect(),izquierda, point, true);
    mov[2] = game->trymove(getDestRect(),arriba, point, true);
    mov[3] = game->trymove(getDestRect(),abajo, point, true);

    if (game->trymove(getDestRect(),dir_actual, point, true)) 
    {
        if (dir_actual == izquierda) { mov[0] = false; }
        else if (dir_actual == derecha) { mov[1] = false; }
        else if (dir_actual == abajo) { mov[2] = false; }
        else if (dir_actual == arriba) { mov[3] = false;}
    }
}

void Ghost::SelecMov()
{
    CheckMov();
    vector<int> sel(4);
    
    for (int cont = 0; cont < 4; cont++) { sel[cont] = cont; }

        int aux = rand() % 4, i = 0;
        while (!mov[aux] && i < 4) {
            // Si la direccion seleccionada esta bloqueada, se descarta
           if (!mov[aux]) {
                int aux2 = 0;
                while (sel[aux2] != aux && aux2 < 4) // Se meteria en este bucle y no saldria
                    aux2++;
                sel[aux] = -1;
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

// Selecciona la direccion y se mueve
void Ghost::update()
{
    /*if (CambMove >= 70 || !game->trymove(getDestRect(), dir_actual, point, true))
    {
        SelecMov();
        CambMove = 0;
    }
    
    if (game->trymove(getDestRect(), dir_actual, point, true))
    {
		SDL_Rect mapRect = game->map();
		Move(point, dir_actual, mapRect);
    }

    CambMove++;*/
}

// Mueve al fantasma a su posicion inicial
void Ghost::morir()
{
    point = iniPoint;
}

// Renderiza a su fantasma con su respectiva textura
void Ghost::render() {
    SDL_Rect rect;
    rect.x = point.getX();
    rect.y = point.getY();
	rect.w = game->CellX();
	rect.h = game->CellY();
    
    if (textura == NULL)
    {
        throw"Los fantasmas no tienen texturas";
    }
	textura->renderFrame(rect, 0, 8);
    

}

void Ghost::saveToFil(ofstream& fil)
{
    fil << "f " << point.getX() << " " << point.getY() << " " 
        << dir_actual.GetX() << " " << dir_actual.GetY() << endl;
}

Ghost::~Ghost()
{
    delete game;
    delete textura;
}