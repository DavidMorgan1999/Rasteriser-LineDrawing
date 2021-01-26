#include "Rasteriser.h"


Rasteriser app;

bool Rasteriser::Initialise() 
{
	
	if (!MD2Loader::LoadModel("cube.md2", _model))
	{
		return false;
	}
	
	return true;

}


void Rasteriser::Update(Bitmap &bitmap)
{
	float width = (float)bitmap.GetWidth();
	float height = (float)bitmap.GetHeight();
	
	transform.YRotationMatrix((float)update);
	GeneratePerspectiveMatrix(1, (width / height));
	GenerateViewMatrix(1, width, height);
	update++;

	
}

void Rasteriser::DrawTriangle(HDC hdc, Vertex vertices[])
{

	SelectObject(hdc, GetStockObject(DC_PEN));
	SetDCPenColor(hdc, RGB(0, 0, 255));
	// Draw up the wireframe with our newly transformed vertices.
	MoveToEx(hdc, (int)vertices[0].GetX(), (int)vertices[0].GetY(), NULL);
	LineTo(hdc, (int)vertices[1].GetX(), (int)vertices[1].GetY());
	LineTo(hdc, (int)vertices[2].GetX(), (int)vertices[2].GetY());
	LineTo(hdc, (int)vertices[0].GetX(), (int)vertices[0].GetY());
}

void Rasteriser::GeneratePerspectiveMatrix(float d, float aspectRatio)
{
	PerspectiveMatrix = {(d/aspectRatio),0,0,0,
				  0, d, 0, 0,
				  0, 0, d, 0,
				  0, 0, 1, 0};
}

void Rasteriser::GenerateViewMatrix(float d, float width, float height)
{
	ViewMatrix = { (width / 2),0,0,(width / 2),
				    0, (-height/2), 0 ,(height/2),
					0, 0, (d/2), (d/2),
					0, 0, 0, 1};
}

void Rasteriser::Render(Bitmap &bitmap)
{
	
	Vertex cameraview = _view.GetPosition();


	_model.ApplyTransformToLocalVertices(transform);
	CameraViewMatrix = _view.ViewingTransformationFull(_view.GetXRotation(), _view.GetYRotation(), _view.GetZRotation(), cameraview.GetX(), cameraview.GetY(), cameraview.GetZ());
	_model.ApplyTransformToTransformedVertices(CameraViewMatrix);
	_model.ApplyTransformToTransformedVertices(PerspectiveMatrix);
	_model.deHomogenise();
	_model.ApplyTransformToTransformedVertices(ViewMatrix);
	DrawWireFrame(_model, bitmap);
}

void Rasteriser::DrawWireFrame(const Model& model, Bitmap &bitmap)
{		


		Model tempModel = model;
		_polygonsR = tempModel.GetPolygons();
		_transformedVerticesR = tempModel.GetTransformedVertices();
		bitmap.Clear(RGB(255, 255, 255));
		for (int i = 0; i < (int)tempModel.GetPolygons().size(); i++)
		{
			Polygon3D tempPoly = tempModel.GetPolygon(i);

				// Polygon obviously has three different points
			vertices[0] = tempModel.GetTransformedVertex(tempPoly.GetIndex(0));
			vertices[0] = tempModel.GetTransformedVertex(tempPoly.GetIndex(1));
			vertices[0] = tempModel.GetTransformedVertex(tempPoly.GetIndex(2));

			

			HDC hdc = bitmap.GetDC();
			DrawTriangle(hdc, vertices);
			

	}

}



void Rasteriser::View(Camera) {
	
	
}






