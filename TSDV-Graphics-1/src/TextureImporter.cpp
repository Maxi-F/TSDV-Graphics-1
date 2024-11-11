#include <iostream>
#include <string>
#include "TextureImporter.h"
#include "Renderer.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void GuichernoEngine::TextureImporter::Import(const char* fileName, TextureData &textureData) {
	glGenTextures(1, &textureData.ID);
	glBindTexture(GL_TEXTURE_2D, textureData.ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	std::string fileNameString = std::string(fileName);
	std::string extension = fileNameString.substr(fileNameString.find_last_of(".") + 1);

	// load and generate the texture
	int nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(fileName, &textureData.width, &textureData.height, &nrChannels, 0);

	GLenum format;
	
	switch (nrChannels) {
		case 3:
			format = GL_RGB;
			break;
		case 4:
			format = GL_RGBA;
			break;
		default:
			format = GL_RGB;
	}

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, format, textureData.width, textureData.height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}
