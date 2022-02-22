#include <Neon/ECS/System/TransformSystem.h>
#include <Neon/ECS/Component.h>
#include <Neon/Neon.h>

NeTransformSystem::NeTransformSystem(Neon* neon)
	: NeSystemBase(neon)
{
}

NeTransformSystem::~NeTransformSystem()
{
}

// Dirty Component set에서 꺼내서 update 하고 현재 프레임 번호 저장
// 하위 Component udpate시 현재 프레임 번화와 비교해서 update 할지 결정
void NeTransformSystem::Update(long frameNumber, double timeDelta)
{
	set<NeTransformComponent*> dirtyComponents;

	auto components = neon->GetComponents<NeTransformComponent>();
	for (auto& component : components)
	{
		auto c = component->As<NeTransformComponent>();
		if (c != nullptr)
		{
			if (c->IsDirty())
			{
				dirtyComponents.insert(c);
			}
		}
	}

	set<NeTransformComponent*> updatedComponents;
	for (auto& c : dirtyComponents)
	{
		stack<NeTransformComponent*> updateStack;
		updateStack.push(c);
		while (updateStack.empty() == false)
		{
			auto top = updateStack.top();
			updateStack.pop();

			if (updatedComponents.count(top) != 0)
				continue;

			if (top->GetParent() != nullptr)
			{
				auto pwm = top->GetParent()->GetWorldTransform();
				top->SetWorldMatrix(pwm * top->GetLocalTransform());
			}
			else
			{
				top->SetWorldMatrix(top->GetLocalTransform());
			}
			top->SetDirty(false);

			updatedComponents.insert(top);

			for (auto& child : c->GetChildren())
			{
				updateStack.push(child);
			}
		}
	}
}

void NeTransformSystem::Render(long frameNumber)
{
	//auto components = neon->GetComponents<NeTransformComponent>();
	//for (auto& component : components)
	//{
	//}
}
