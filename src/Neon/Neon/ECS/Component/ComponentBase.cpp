#include <Neon/ECS/Component/ComponentBase.h>
#include <Neon/Graphics/Buffer.hpp>

NeComponentBase::NeComponentBase()
{
	this->componentType = typeid(this).name();
}

NeComponentBase::~NeComponentBase()
{
}
