
#include "Ghost.h"
#include "Vector2D.h"
#include "Texture.h"
#include "Game.h"
#include <vector>
#include <cstdlib>


Ghost::Ghost(int x, int y, Game* g) : GameCharacter(Point2D(x, y), Vector2D(1, 0), g->getTexture(characters), g) {

}

// Comprobamos las direcciones a las que se puede mover el fantasma
void Ghost::CheckMov() //Comprobar que se puede mover en x direccion
{
    Vector2D derecha(1, 0), izquierda(-1, 0), arriba(0, -1), abajo(0, 1);

    mov[0] = game->nextCell(derecha, point);
    mov[1] = game->nextCell(izquierda, point);
    mov[2] = game->nextCell(arriba, point);
    mov[3] = game->nextCell(abajo, point);

    if (game->nextCell(dir_actual, point)) {
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
                while (sel[aux2] != aux)
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

// Selecciona la direccion y se mueve
void Ghost::update()
{
    SelecMov();
    game->tryMove(getDestRect(), dir_actual, point);
}

// Mueve al fantasma a su posicion inicial
void Ghost::morir()
{
    point = iniPoint;
}

// Renderiza a su fantasma con su respectiva textura
void Ghost::render(int aux) {
    SDL_Rect rect;
    rect.x = point.getX() * 10;
    rect.y = point.getY() * 10;
    rect.w = 10;
    rect.h = 10;
    
    if (textura == NULL)
    {
        throw"Los fantasmas no tienen texturas";
    }
        if (aux == 0)
            textura->renderFrame(rect, 0, 0);
        else if (aux == 1)
            textura->renderFrame(rect, 0, 2);
        else if (aux == 2)
            textura->renderFrame(rect, 0, 4);
        else
            textura->renderFrame(rect, 0, 6);
    

}

Ghost::~Ghost()
{
    delete game;
    delete textura;
}