#pragma once
#include "Vector2D.h"
#include "Texture.h"
#include "PlayState.h"
#include "checkML.h"
class Game;

class GameObject 
{
protected:
	Point2D point;
	int w, h;
	Game* game;
	PlayState* play;
public:

	GameObject(Point2D p, int w1, int h1, Game* g, PlayState* pl) : point(p), w(w1), h(h1), game(g), play(pl) {}
	virtual ~GameObject() {}
	virtual void update() = 0; // GameMap tiene que tener el update y el render preparados
	virtual void render() = 0;
	Point2D getPoint() { return point; }
	virtual SDL_Rect getDestRect() = 0;
};
