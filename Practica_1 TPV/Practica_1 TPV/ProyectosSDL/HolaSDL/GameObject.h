#pragma once
#include "Game.h"
#include "Vector2D.h"

class GameObject 
{
private:
	Point2D pos;
	int anch, alt;
	Game* g;
public:

	virtual ~GameObject() {};
	virtual void update();
	virtual void render() const;
	virtual void getDestRect(int& an, int& al) { an = anch; al = alt; };
};
