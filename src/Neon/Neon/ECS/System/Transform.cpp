#include <Neon/ECS/System.h>
#include <Neon/ECS/Component.h>
#include <Neon/Neon.h>

NeSystemBase::NeSystemBase(Neon* neon)
	: neon(neon)
{
}

NeSystemBase::~NeSystemBase()
{
}

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

NeMeshSystem::NeMeshSystem(Neon* neon)
	: NeSystemBase(neon)
{
}

NeMeshSystem::~NeMeshSystem()
{
}

void NeMeshSystem::Update(long frameNumber, double timeDelta)
{
	//auto components = neon->GetComponents<NeMeshComponent>();
	//for (auto& component : components)
	//{
	//}
}

void NeMeshSystem::Render(long frameNumber)
{
	//auto components = neon->GetComponents<NeMeshComponent>();
	//for (auto& component : components)
	//{
	//	((NeMeshComponent*)component)->Draw();
	//}
}

NeMeshRendererSystem::NeMeshRendererSystem(Neon* neon)
	: NeSystemBase(neon)
{
}

NeMeshRendererSystem::~NeMeshRendererSystem()
{
}

void NeMeshRendererSystem::Update(long frameNumber, double timeDelta)
{
	//auto components = neon->GetComponents<NeMeshRendererComponent>();
	//for (auto& component : components)
	//{
	//}
}

void NeMeshRendererSystem::Render(long frameNumber)
{
	auto components = neon->GetComponents<NeMeshRendererComponent>();
	for (auto& component : components)
	{
		auto meshRenderer = component->As<NeMeshRendererComponent>();
		if (meshRenderer != nullptr)
		{
			auto transform = meshRenderer->GetTransform();
			auto mesh = meshRenderer->GetMesh();
			auto material = meshRenderer->GetMaterial();

			if (material != nullptr)
			{
				material->Use();

				auto shader = material->GetShader();
				if (shader != nullptr)
				{
					if (shader->SetUniformMatrix4("transform", transform->GetWorldTransform()) == false)
					{
						SPDLOG_CRITICAL("Failed to set trasform matrix in shader.");
					}
				}

				auto texture = material->GetTexture();
				if (texture != nullptr)
				{
					texture->Bind();
				}
			}

			mesh->Draw();
		}
	}
}

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
