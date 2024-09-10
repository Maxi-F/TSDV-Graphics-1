#pragma once

namespace GuichernoEngine
{
	const int MAX_ARRAY_SIZE = 256;

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