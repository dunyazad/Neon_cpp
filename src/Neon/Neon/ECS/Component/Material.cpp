#include <Neon/ECS/Component/Material.h>
#include <Neon/ECS/Component/Shader.h>

NeMaterialComponent::NeMaterialComponent()
	: NeComponentBase()
{
}

NeMaterialComponent::~NeMaterialComponent()
{
}

void NeMaterialComponent::Use()
{
	if (this->shaderComponent != nullptr)
	{
		this->shaderComponent->Use();
	}
}
