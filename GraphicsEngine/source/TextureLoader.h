#pragma once

class TextureLoader
{
public:
	TextureLoader() {}
	~TextureLoader() {}

	GLuint GetTextureID(std::string texFileName);
};

