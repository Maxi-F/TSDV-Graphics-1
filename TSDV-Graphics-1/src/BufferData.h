#pragma once

namespace GuichernoEngine
{
	struct BufferData
	{
		unsigned int VBO;
		unsigned int IBO;
		float* vertices;
		unsigned int* indices;
		unsigned int vertexCount;
		unsigned int indexCount;
	};
}