#pragma once
#include <Neon/NeonCommon.h>

class NeShader;
class NeTexture;

class NeMaterial
{
public:
	NeMaterial();
	virtual ~NeMaterial();

	void Use();

	inline NeShader* GetShader() const { return this->shader; }
	inline void SetShader(NeShader* s) { this->shader = s; }

	inline NeTexture* GetTexture() const { return this->texture; }
	inline void SetTexture(NeTexture* t) { this->texture = t; }

private:
	NeShader* shader = nullptr;
	NeTexture* texture = nullptr;
};
