#pragma once
#include "Vector2D.h"
#include "Texture.h"
#include "checkML.h"
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
	virtual void update() = 0; // Esto obliga a las clases que hereden GameObject, a tener su propio update, render y getDestRect
	virtual void render() = 0;
    Point2D getPoint() { return point; }
	virtual SDL_Rect getDestRect() = 0;
};
