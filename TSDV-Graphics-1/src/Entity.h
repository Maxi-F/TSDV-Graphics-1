#pragma once
#include "BufferData.h"
#include "Renderer.h"

namespace GuichernoEngine 
{
	class Entity 
	{
		public:
			void Init(float vertices[], unsigned int vertexCount, unsigned int count);

			virtual void Draw() = 0;
			BufferData bufferData;

			
	};
}
