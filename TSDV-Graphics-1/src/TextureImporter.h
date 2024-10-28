#pragma once
#include "TextureData.h"

namespace GuichernoEngine {
	class TextureImporter {
		public:
			static void Import(const char* fileName, TextureData &textureData);
	};
}
