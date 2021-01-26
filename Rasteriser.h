#pragma once
#include <vector>
#include "Framework.h"
#include "Matrix.h"
#include "Bitmap.h"
#include "Vertex.h"
#include "Model.h"
#include "Polygon3D.h"
#include "MD2Loader.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include "Camera.h"
#include <GdiPlus.h>
#include <string>


class Rasteriser : public Framework
{
public:
	bool Initialise();
	void Update(Bitmap &bitmap);
	void Render(Bitmap &bitmap);
	void DrawWireFrame(const Model& model, Bitmap &bitmap);
	void View(Camera);
private:
	void DrawTriangle(HDC hdc, Vertex Vertices[]);

	void GeneratePerspectiveMatrix(float d, float aspectRatio);

	void GenerateViewMatrix(float d, float width, float height);

	Vertex vertices[3];
	Matrix transform;
	Model _model;
	Camera _view;
	Matrix CameraViewMatrix;
	Matrix PerspectiveMatrix;
	Matrix ViewMatrix;
	Matrix ModelTransformation;
	int update = 1;
	int index1;
	int index2;
	int index3;
	
	std::vector<Polygon3D> _polygonsR;
	std::vector<Polygon3D> _verticesR;
	std::vector<Vertex> _transformedVerticesR;
	float _x;
	float _y;
};


