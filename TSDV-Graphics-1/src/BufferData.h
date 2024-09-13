#pragma once
#include "ExportHeader.h"

namespace GuichernoEngine
{
	struct GUICHERNO_API BufferData
	{
		unsigned int VBO;
		unsigned int IBO;
		float* vertices;
		unsigned int* indices;
		unsigned int vertexCount;
		unsigned int indexCount;
	};
}