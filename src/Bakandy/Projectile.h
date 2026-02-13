#pragma once

#include <iostream>

#include "Geometry.h"

class Projectile : public Geometry
{
protected:
	int m_MoveX;
	int m_MoveY;
	int m_dgt;

public:
	Projectile(int x, int y, int wi, int he, int dgt, int mx, int my);

	virtual bool MoveP(float deltaTime) = 0;

	int GetDgt() { return m_dgt; }

};

