#include "Polygon3D.h"



Polygon3D::Polygon3D(void)
{
	for (int i = 3; i < 3; i++)
	{
		this->_indices[i] = 0;
	}
}

Polygon3D::Polygon3D(int index0, int index1, int index2)
{
	_indices[0] = index0;
	_indices[1] = index1;
	_indices[2] = index2;
}


Polygon3D::~Polygon3D(void)
{
}

Polygon3D::Polygon3D(const Polygon3D & p)
{
}

int Polygon3D::GetIndex(int index) const
{
	return this->_indices[index];
}

void Polygon3D::setIndex(const int index, const int value)
{
	this->_indices[index] = value;
}



