
#include "Ghost.h"
#include "Vector2D.h"
#include "Texture.h"
#include "Game.h"
#include <vector>


Ghost::Ghost(int x, int y, Game* g) : iniPoint(x, y), point(x, y) {
	game = g;
	tfantasmas = g->getTexture(characters);
}


direction Ghost::CheckMov() //Comprobar que se puede mover en x direccion
{
    //Direccion abajo
    if (game->getMapa()->readCell(point.getX(), point.getY() + 1) != Wall)
    {
        mov[3] = true;
    }
    else mov[3] = false;

    //Direccion arriba
    if (game->getMapa()->readCell(point.getX(), point.getY() - 1) != Wall)
    {
        mov[1] = true;
    }
    else mov[1] = false;

    //Direccion derecha
    if (game->getMapa()->readCell(point.getX() + 1, point.getY()) != Wall)
    {
        mov[2] = true;
    }
    else mov[2] = false;

    //Direccion izquierda
    if (game->getMapa()->readCell(point.getX() - 1, point.getY()) != Wall)
    {
        mov[0] = true;
    }
    else mov[0] = false;


    return SelecMov();
}


direction Ghost::SelecMov()
{
    vector<direction> variantsOfDirection;

    direction direc;

    for (int i = 0; i < mov.size(); i++)//Almacenar las direcciones posibles
    {
        if (mov[i])
        {
            if (i == 0) variantsOfDirection.push_back(direction::left);
            else if (i == 1) variantsOfDirection.push_back(up);
            else if (i == 2) variantsOfDirection.push_back(direction::right);
            else variantsOfDirection.push_back(down); //i == 3
        }

    }
   

        int pos = rand() % (variantsOfDirection.size() + 1); //Numero random
        
        
        
        direc = variantsOfDirection[1]; // Preguntar como acceder a cierta posicion de la lista


        return direc;
    
}


void Ghost::CambiaPos()
{
    direction aux = CheckMov();
    switch (aux)
    {
        case direction::left:
        {
            point.Suma(-1, 0);
            break;
        }
        case direction::right:
        {
            point.Suma(1, 0);
            break;
        }
        case up:
        {
            point.Suma(0, -1);
            break;
        }
        case down:
        {
            point.Suma(0, 1);
            break;
        }
    }

}

void Ghost::update() 
{
    CambiaPos();
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