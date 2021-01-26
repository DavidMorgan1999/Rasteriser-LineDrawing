#include "Model.h"
#include <Windows.h>
#include <iostream>


Model::Model()
{
}


Model::~Model()
{
}

std::vector<Polygon3D>& Model::GetPolygons()
{
	return this->_polygons;
}

std::vector<Vertex>& Model::GetVertices()
{
	return this->_vertices;
}

std::vector<Vertex>& Model::GetTransformedVertices()
{
	return this->_transformedVertices;
}

size_t Model::GetPolygonCount() const
{
	return size_t(_polygons.size());
}

size_t Model::GetVertexCount() const
{
	return size_t(_vertices.size());
}

size_t Model::GetTransformedVertexCount() const
{
	return size_t(_transformedVertices.size());
}

void Model::AddVertex(float x, float y, float z)
{
	Vertex _temp;

	_temp.SetX(x);
	_temp.SetY(y);
	_temp.SetZ(z);

	_vertices.push_back(_temp);
	
}

void Model::AddPolygon(int i0, int i1, int i2)
{
	Polygon3D p;
	p.setIndex(0, i0);
	p.setIndex(1, i1);
	p.setIndex(2, i2);
	_polygons.push_back(Polygon3D(p));
	
}

void Model::ApplyTransformToLocalVertices(const Matrix & transform)
{
	_transformedVertices.clear();
	Vertex p;
	for (int i = 0; i < (int)GetVertexCount(); i++) {
		 p = transform*(_vertices[i]);	
		 _transformedVertices.push_back(p);
	}
}

void Model::ApplyTransformToTransformedVertices(const Matrix& transform)
{
	
	for (int i = (int)GetTransformedVertexCount()-1; i >= 0; i--) {
		
		_transformedVertices[i] = transform * _transformedVertices[i];;
	}
}

void Model::deHomogenise()
{
	
	for (int i = (int)GetTransformedVertexCount()-1; i >= 0; i--) {
	
		_transformedVertices[i].dehomogenise();
	}

}

const Vertex& Model::GetTransformedVertex(int i)
{
	return _transformedVertices[i];
}

const Polygon3D & Model::GetPolygon(int i) 
{
	return this->_polygons[i];
}

const Vertex & Model::GetVertex(int i)
{
	return this->_vertices[i];
}



