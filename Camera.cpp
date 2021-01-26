#include "Camera.h"



Camera::Camera()
{
	Vertex p(0, 0, -50);
	xRotation_ = 0.0f;
	yRotation_ = 0.0f;
	zRotation_ = 0.0f;
	Pos_.operator=(p);
}

Camera::Camera(float xRotation, float yRotation, float zRotation, const Vertex & position)
{
	xRotation = xRotation_;
	yRotation = yRotation_;
	zRotation = zRotation_;
	position.operator+(Pos_);
}


Camera::~Camera()
{
}

float Camera::GetXRotation() const
{
	return xRotation_;
}

void Camera::SetXRotation(const float x)
{
	xRotation_ = x;
}

float Camera::GetYRotation() const
{
	return yRotation_;
}

void Camera::SetYRotation(const float y)
{
	yRotation_ = y;
}

float Camera::GetZRotation() const
{
	return zRotation_;
}

void Camera::SetZRotation(const float z)
{
	zRotation_ = z;
}

Vertex Camera::GetPosition() const
{
	return Pos_;
}

void Camera::SetPosition(const Vertex Pos)
{
	Pos_ = Pos;
}

Matrix Camera::ViewingTransformation(float x, float y, float z)
{
	return Matrix{1, 0, 0, -x,
			      0, 1, 0, -y,
			      0, 0, 1, -z,
				  0, 0, 0, 1};
}

Matrix Camera::ViewingTransformationXRotation(float angle)
{
	return Matrix{1, 0, 0, 0,
				  0, cos(angle),sin(angle), 0,
				  0, -sin(angle), cos(angle), 0,
				  0, 0, 0, 1};
}

Matrix Camera::ViewingTransformationYRotation(float angle)
{
	return Matrix{cos(angle),0,-sin(angle),0,
				  0, 1, 0, 0,
				  sin(angle),0, cos(angle),0,
				  0,0,0,1};
}

Matrix Camera::ViewingTransformationZRotation(float angle)
{
	return Matrix{cos(angle),sin(angle),0,0,
				  -sin(angle),cos(angle),0,0,
				 0,0,1,0,
				0,0,0,1};
}

Matrix Camera::ViewingTransformationFull(float angleX, float angleY, float angleZ, float x, float y, float z)
{
	return Matrix(ViewingTransformation(x, y, z)*ViewingTransformationXRotation(angleX)*ViewingTransformationYRotation(angleY)*ViewingTransformationZRotation(angleZ));
}


