#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/ECS/Component/ComponentBase.h>

class NeTextureComponent : public NeComponentBase
{
public:
	NeTextureComponent();
	virtual ~NeTextureComponent();

	void Bind();
	void Unbind();

	void LoadFromFile(const string& filePath, int width, int height, GLenum textureTarget = GL_TEXTURE_2D);

protected:
	unsigned int textureID = UINT_MAX;
	GLenum textureTargetID = GL_TEXTURE_2D;
};
