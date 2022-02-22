#include <Neon/ECS/Component/MaterialComponent.h>
#include <Neon/ECS/Component/ShaderComponent.h>

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
