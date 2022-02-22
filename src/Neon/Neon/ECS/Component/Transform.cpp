#include <Neon/ECS/Component/Transform.h>

NeTransformComponent::NeTransformComponent()
	: NeComponentBase()
{
}

NeTransformComponent::~NeTransformComponent()
{
}

void NeTransformComponent::AttachChild(NeTransformComponent* child)
{
	if (child->parent != nullptr)
	{
		child->parent->children.erase(child);
	}
	child->parent = this;
	this->children.insert(child);
}

void NeTransformComponent::DetachChild(NeTransformComponent* child)
{
	if (child->parent == this)
	{
		child->parent = nullptr;
	}
	this->children.erase(child);
}
