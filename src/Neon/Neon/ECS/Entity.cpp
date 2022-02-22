#include <Neon/ECS/Entity.h>

NeEntityBase::NeEntityBase()
{
}

NeEntityBase::~NeEntityBase()
{
}

void NeEntityBase::OnUpdate(function<void(double)> callback)
{
	this->updateCallbacks.push_back(callback);
}

void NeEntityBase::OnRender(function<void(void)> callback)
{
	this->renderCallbacks.push_back(callback);
}

const list<NeComponentBase*>& NeEntityBase::GetComponents()
{
	return this->components;
}

void NeEntityBase::AddComponent(NeComponentBase* component)
{
	this->components.push_back(component);
}

void NeEntityBase::RemoveComponent(NeComponentBase* component)
{
	this->components.remove(component);
}
