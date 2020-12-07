#include "GameObject.h"



void GameObject::update()
{
	
}


SDL_Rect GameObject::getDestRect()
{ 
	SDL_Rect aux;
	aux.x = pos.getX();
	aux.y = pos.getY();

	aux.w = anch;
	aux.h = alt;
	return aux;
}

/*void GameObject::render()
{
	
}*/
