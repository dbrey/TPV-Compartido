#pragma once
#include "Game.h"
#include "Vector2D.h"

class GameObject 
{
protected:
	Point2D point;
	int w, h;
	Game* game;
public:

	GameObject(Point2D p, int w1, int h1, Game* g) : point(p), w(w1), h(h1), game(g) {}
	virtual ~GameObject() {}
	virtual void update() = 0;
	virtual void render() = 0;
	virtual SDL_Rect getDestRect() = 0;
};
