#pragma once

#include "Vector2D.h"
#include "Texture.h"
#include "GameCharacter.h"
#include <array>
class Game;


class Ghost : public GameCharacter
{

private:
	array<bool, 4> mov; //  0 = left   1 = up    2 = right    3 = down

public:
	Ghost(int x, int y, Game* g);

	void CheckMov();
	void SelecMov();
	void update();
	void morir();
	void render(int aux);

	~Ghost();
};