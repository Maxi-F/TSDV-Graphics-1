#pragma once
#include "Entity2D.h"
#include "RectangleData.h"
#include "TextureData.h"
#include "UvCoords.h"

namespace GuichernoEngine 
{
	class Sprite : public Entity2D
	{
		private:
			static float* CreateSquareVertices();

		public:
			TextureData texture;
			GUICHERNO_API static Sprite* FromRectangle(const char* filePath, RectangleData data, Color color);
			GUICHERNO_API Sprite(const char* filePath, float* vertices, unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType);
			GUICHERNO_API int GetTextureWidth();
			GUICHERNO_API int GetTextureHeight();
			GUICHERNO_API ~Sprite();
			void SetUvCoords(UvCoords topLeftUvCoords, UvCoords bottomRightUvCoords);

			GUICHERNO_API void Draw();
	};
}
