#include "SmartGhost.h"

// Llama al update de Ghost o al de SmartGhost
void SmartGhost::update()
{
	CheckMov();
	if (mov[0] && point.getX() > game->getPac()->getPoint().getX()) // left
	{
		
	} 
	else if (mov[1]) // up
	{

	}
	else if (mov[2]) // right
	{

	}
	else // down
	{

	}
	
}