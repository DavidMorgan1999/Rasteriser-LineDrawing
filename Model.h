#pragma once
#include <iostream>
#include <vector>
#include "Polygon3D.h"
#include "Vertex.h"
#include "Matrix.h"
#include <iostream>

class Model
{
public:
	Model();
	~Model();
	// Accessors
	std::vector<Polygon3D>& GetPolygons();
	std::vector<Vertex>& GetVertices();
	std::vector<Vertex>& GetTransformedVertices();
	size_t GetPolygonCount() const;
	size_t GetVertexCount() const;
	size_t GetTransformedVertexCount() const;
	int test;

	void AddVertex(float x, float y, float z);
	
	void AddPolygon(int i0, int i1, int i2);

	void ApplyTransformToLocalVertices(const Matrix &transform);
	void ApplyTransformToTransformedVertices(const Matrix &transform);

	void deHomogenise();
	const Vertex& Model::GetTransformedVertex(int i);
	const Polygon3D& Model::GetPolygon(int i);
	const Vertex& Model::GetVertex(int i);
	

private:
	std::vector<Polygon3D> _polygons;
	std::vector<Vertex> _vertices;
	std::vector<Vertex> _transformedVertices;
};