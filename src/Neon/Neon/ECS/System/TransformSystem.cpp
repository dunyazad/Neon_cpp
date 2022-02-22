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

// Dirty Component set���� ������ update �ϰ� ���� ������ ��ȣ ����
// ���� Component udpate�� ���� ������ ��ȭ�� ���ؼ� update ���� ����
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
