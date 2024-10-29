#pragma once
#include "Entity2D.h"
#include "RectangleData.h"
#include "TextureData.h"
#include "UvCoords.h"
#include "Animation.h"

namespace GuichernoEngine 
{
	class Sprite : public Entity2D
	{
		private:
			static float* CreateSquareVertices();

		public:
			TextureData texture;
			Animation* animation;
			GUICHERNO_API static Sprite* FromRectangle(const char* filePath, RectangleData data, Color color);
			GUICHERNO_API static Sprite* FromRectangle(const char* filePath, RectangleData data, Animation* animation, Color color);
			GUICHERNO_API Sprite(const char* filePath, float* vertices, unsigned int vertexLength, unsigned int arrayLength, ShapeType shapeType);
			GUICHERNO_API int GetTextureWidth();
			GUICHERNO_API int GetTextureHeight();
			GUICHERNO_API ~Sprite();
			GUICHERNO_API void SetAnimation(Animation* animation);
			GUICHERNO_API void Update();
			void SetUvCoords(UvCoords topLeftUvCoords, UvCoords bottomRightUvCoords);

			GUICHERNO_API void Draw();
	};
}
