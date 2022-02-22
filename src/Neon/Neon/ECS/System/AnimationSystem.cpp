#include <Neon/ECS/System/AnimationSystem.h>
#include <Neon/Neon.h>

NeAnimatorSystem::NeAnimatorSystem(Neon* neon)
	: NeSystemBase(neon)
{
}

NeAnimatorSystem::~NeAnimatorSystem()
{
}

void NeAnimatorSystem::Update(long frameNumber, double timeDelta)
{
	auto components = neon->GetComponents<NeAnimatorComponent>();
	for (auto& component : components)
	{
		auto animator = component->As<NeAnimatorComponent>();
		if (animator != nullptr)
		{
			for (auto& callback : animator->GetUpdateCallbacks())
			{
				callback(animator->GetTransform(), frameNumber, timeDelta);
			}
		}
	}
}

void NeAnimatorSystem::Render(long frameNumber)
{
}
