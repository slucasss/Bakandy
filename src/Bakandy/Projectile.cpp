#include "Projectile.h"


Projectile::Projectile(int x, int y, int wi, int he, int dgt, int mx, int my) :
Geometry(wi, he)
	{
	this->SetPosition(x, y, 0.5, 0.5);
	m_dgt = dgt;
	m_MoveX = mx;
	m_MoveY = my;
}
