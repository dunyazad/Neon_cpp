#pragma once

#include <Neon/NeonCommon.h>

class NeTexture
{
public:
	NeTexture();
	virtual ~NeTexture();

	void Bind();
	void Unbind();

	void LoadFromFile(const string& filePath, int width, int height, GLenum textureTarget = GL_TEXTURE_2D);

protected:
	unsigned int textureID = UINT_MAX;
	GLenum textureTargetID = GL_TEXTURE_2D;
};
