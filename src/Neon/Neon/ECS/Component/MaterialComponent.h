#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/ECS/Component/ComponentBase.h>

class NeShaderComponent;
class NeTextureComponent;

class NeMaterialComponent : public NeComponentBase
{
public:
	NeMaterialComponent();
	virtual ~NeMaterialComponent();

	void Use();

	inline NeShaderComponent* GetShader() const { return this->shaderComponent; }
	inline void SetShader(NeShaderComponent* shader) { this->shaderComponent = shader; }

	inline NeTextureComponent* GetTexture() const { return this->textureComponent; }
	inline void SetTexture(NeTextureComponent* texture) { this->textureComponent = texture; }

protected:
	NeShaderComponent* shaderComponent = nullptr;
	NeTextureComponent* textureComponent = nullptr;
};
