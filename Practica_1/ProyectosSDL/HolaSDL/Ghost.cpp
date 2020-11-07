
#include "Ghost.h"
#include "Vector2D.h"
#include "Texture.h"
#include "Game.h"
#include <vector>

//void Ghost::Render()

//direction Ghost::CheckMov(GameMap m) //Comprobar que se puede mover en x direccion
//{
//    //Direccion abajo
//    if (mapa->readCell(point.getX(), point.getY() + 1) != Wall)
//    {
//        mov[3] = true;
//    }
//    else mov[3] = false;
//
//    //Direccion arriba
//    if (mapa->readCell(point.getX(), point.getY() - 1) != Wall)
//    {
//        mov[1] = true;
//    }
//    else mov[1] = false;
//
//    //Direccion derecha
//    if (mapa->readCell(point.getX() + 1, point.getY()) != Wall)
//    {
//        mov[2] = true;
//    }
//    else mov[2] = false;
//
//    //Direccion izquierda
//    if (point.getX() - 1, point.getY())
//    {
//        mov[0] = true;
//    }
//    else mov[0] = false;
//
//
//    return SelecMov();
//}
//
//
//direction Ghost::SelecMov()
//{
//    vector<direction> variantsOfDirection;
//
//    direction direc;
//
//    for (int i = 0; i < mov.size(); i++)//Almacenar las direcciones posibles
//    {
//        if (mov[i])
//        {
//            if (i == 0) variantsOfDirection.push_back(left);
//            else if (i == 1) variantsOfDirection.push_back(up);
//            else if (i == 2) variantsOfDirection.push_back(right);
//            else variantsOfDirection.push_back(down); //i == 3
//        }
//
//    }
//   
//
//        int pos = rand() % (variantsOfDirection.size() + 1); //Numero random
//        
//        
//        
//        direc = variantsOfDirection[1]; // Preguntar como acceder a cierta posicion de la lista
//
//
//        return direc;
//    
//}
//
//void Ghost::MovementVerde(GameMap* m)
//{
//
//    dir = CheckMov(m);
//
//    switch (dir)
//    {
//    case down:
//
//        direc.abajo();
//        break;
//    case up:
//
//        direc.arriba();
//
//        break;
//    case right:
//        direc.derecha();
//        
//            if () //Si esta en el teleport
//            {
//                //nueva posicion
//            }
//        
//        break;
//    case left:
//        
//        direc.izquierda();
//
//            if () //Si esta en el teleport
//            {
//                //nueva posicion
//            }
//        
//        break;
//    }