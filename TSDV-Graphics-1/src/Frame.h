#pragma once
#include "UvCoords.h"
#include "ExportHeader.h"

namespace GuichernoEngine 
{
	class GUICHERNO_API Frame
	{
		public:
			UvCoords topLeftUVCoords;
			UvCoords bottomRightUVCoords;
			Frame(UvCoords topLeftUVCoords, UvCoords bottomRightUVCoords);
			~Frame();
	};
}
