#pragma once
#include "Model.h"
class Camera
{
public:
	Camera();
	Camera(float xRotation, float yRotation, float zRotation, const Vertex& position);
	~Camera();

	float GetXRotation() const;
	void SetXRotation(const float x);
	float GetYRotation() const;
	void SetYRotation(const float y);
	float GetZRotation() const;
	void SetZRotation(const float z);
	Vertex GetPosition() const;
	void SetPosition(const Vertex Pos);

	static Matrix ViewingTransformation(float x, float y, float z);

	static Matrix ViewingTransformationXRotation(float angle);

	static Matrix ViewingTransformationYRotation(float angle);

	static Matrix ViewingTransformationZRotation(float angle);

	static Matrix ViewingTransformationFull(float angleX, float angleY, float angleZ, float x, float y, float z);

private:
	float xRotation_;
	float yRotation_;
	float zRotation_;
	Vertex Pos_;
};

