#pragma once
#include "BufferData.h"
#include "ExportHeader.h"

namespace GuichernoEngine 
{
	class GUICHERNO_API Entity
	{
		public:
			BufferData bufferData = {};
			void Init(float vertices[], unsigned int vertexCount, unsigned int count);

			virtual void Draw() = 0;
			~Entity();
	};
}
