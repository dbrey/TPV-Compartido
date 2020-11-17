
#include "Ghost.h"
#include "Vector2D.h"
#include "Texture.h"
#include "Game.h"
#include <vector>
#include <cstdlib>


Ghost::Ghost(int x, int y, Game* g) : iniPoint(x, y), point(x, y) {
	game = g;
	tfantasmas = g->getTexture(characters);
}


void Ghost::CheckMov() //Comprobar que se puede mover en x direccion
{
    Vector2D derecha(1, 0);
    Vector2D izquierda(-1, 0);
    Vector2D arriba(0, -1);
    Vector2D abajo(0, 1);
    
    mov[0] = game->nextCell(derecha, point);
    mov[1] = game->nextCell(izquierda, point);
    mov[2] = game->nextCell(arriba, point);
    mov[3] = game->nextCell(abajo, point);
}


void Ghost::SelecMov()
{
    CheckMov();
    vector<int> sel(4);

    for (int x = 0; x < 4; x++)
    {
        sel[x] = x;
    }

    int aux = rand() % 4;
    int i = 0;
    while (!mov[aux] && i < 4)
    {
        // Si la direccion seleccionada esta bloqueada, se descarta
        if (!mov[aux])
        {
            int gg = 0;
            while (sel[gg] != aux)
            {
                gg++;
            }
            sel[gg] = -1;
        }

        // Escogemos una nueva direccion posible
        aux = rand() % 4;
        while (sel[aux] == -1)
        {
            aux = rand() % 4;
        }
        i++;
    }

    if (mov[aux])
    {
        switch (aux)
        {
            // derecha
        case 0:
        {
            direc.setdir(1, 0);
            break;
        }
        // izquierda
        case 1:
        {
            direc.setdir(-1, 0);
            break;
        }
        // arriba
        case 2:
        {
            direc.setdir(0, -1);
            break;
        }
        // abajo
        case 3:
        {
            direc.setdir(0, 1);
            break;
        }
        }
    }
    else {
        direc.setdir(0, 0);
    }
}

void Ghost::update()
{
    SelecMov();
    if (direc.GetX() == -1) {
        point.Suma(-1, 0);
    }
    else if (direc.GetX() == 1) {
        point.Suma(1, 0);
    }
    else if (direc.GetY() == -1) {
        point.Suma(0, -1);
    }
    else if (direc.GetY() == 1) {
        point.Suma(0, 1);
    }

    Point2D izq(0, 15);
    Point2D der(28, 15);
    if (point.iguales(izq))
    {
        point.SetPos(27, 15);
    }
    else if (point.iguales(der))
    {
        point.SetPos(1, 15);
    }

    direc.setdir(0, 0);

}

void Ghost::morir()
{
    point = iniPoint;
}

void Ghost::render(int aux) {
    SDL_Rect rect;
    rect.x = point.getX() * 10;
    rect.y = point.getY() * 10;
    rect.w = 10;
    rect.h = 10;
    if (aux == 0)
    {
        tfantasmas->renderFrame(rect, 0, 0);
    }
    else if (aux == 1)
    {
        tfantasmas->renderFrame(rect, 0, 2);
    }
    else if (aux == 2 )
    {
        tfantasmas->renderFrame(rect, 0, 4);
    }
    else
    {
        tfantasmas->renderFrame(rect, 0, 6);
    }
}

Ghost::~Ghost()
{
    delete game;
    delete tfantasmas;
    
}