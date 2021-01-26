#pragma once
#include "Model.h"

// Forward reference
class Model;

class MD2Loader
{
public:
	MD2Loader(void);
	~MD2Loader(void);
	static bool LoadModel(const char* md2Filename, Model& model);
};
