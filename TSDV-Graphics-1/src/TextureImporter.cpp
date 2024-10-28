#include <iostream>
#include <string>
#include "TextureImporter.h"
#include "Renderer.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void GuichernoEngine::TextureImporter::Import(const char* fileName, TextureData &textureData) {
	glGenTextures(1, &textureData.ID);
	glBindTexture(GL_TEXTURE_2D, textureData.ID);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	std::string fileNameString = std::string(fileName);
	std::string extension = fileNameString.substr(fileNameString.find_last_of(".") + 1);
	bool isRgba = extension == "png";

	// load and generate the texture
	int nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(fileName, &textureData.width, &textureData.height, &nrChannels, isRgba ? STBI_rgb_alpha : STBI_rgb);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, isRgba ? GL_RGBA : GL_RGB, textureData.width, textureData.height, 0, isRgba ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}
