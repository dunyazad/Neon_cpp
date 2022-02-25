#pragma once
#include <Neon/Graphics/Material.h>
#include <Neon/Graphics/Shader.h>
#include <Neon/Graphics/Texture.h>

NeMaterial::NeMaterial()
{
}

NeMaterial::~NeMaterial()
{
}

void NeMaterial::Use()
{
	if (this->shader != nullptr)
	{
		this->shader->Use();
	}

	if (this->texture != nullptr)
	{
		this->texture->Bind();
	}
}
