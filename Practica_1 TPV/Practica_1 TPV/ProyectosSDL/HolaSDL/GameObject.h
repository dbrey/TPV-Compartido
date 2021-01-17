#pragma once
#include "Vector2D.h"
#include "Texture.h"
class Game;

class GameObject 
{
protected:
	Point2D point;
	int w, h;
	Game* game;
public:

	GameObject(Point2D p, int w1, int h1, Game* g) : point(p), w(w1), h(h1), game(g){}
	virtual ~GameObject() {}
	virtual void update() = 0; // GameMap tiene que tener el update y el render preparados
	virtual void render() = 0;
    Point2D getPoint() { return point; }
	virtual SDL_Rect getDestRect() = 0;
};
