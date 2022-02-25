#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/Graphics/Buffer.hpp>

#include <Neon/Component.h>

class NeSystemBase
{
public:
	NeSystemBase(entt::registry* registry) : registry(registry) {}
	virtual ~NeSystemBase() {}

	virtual void Update(long frameNumber, double timeDelta) {}
	virtual void Render(long frameNumber) {}

	inline entt::registry* GetRegistry() { return this->registry; }

	template<typename T>
	T& GetComponent(NeEntity entity)
	{
		return this->GetRegistry()->get<T>(entity);
	}

	template<typename T>
	bool HasComponent(NeEntity entity)
	{
		return this->GetRegistry()->has<T>(entity);
	}

private:
	entt::registry* registry = nullptr;
};

class NeTransformSystem : public NeSystemBase
{
public:
	NeTransformSystem(entt::registry* registry) : NeSystemBase(registry)
	{
	}

	virtual ~NeTransformSystem()
	{
	}
	
	virtual void Update(long frameNumber, double timeDelta)
	{
		auto entities = this->GetRegistry()->view<NeTransformComponent>();
		for (auto& entity : entities)
		{
			auto& transform = this->GetComponent<NeTransformComponent>(entity);
			if (this->HasComponent<NeAnimatorComponent>(entity))
			{
				auto& animator = this->GetComponent<NeAnimatorComponent>(entity);
				animator.updateCallback(transform.localTransform, frameNumber, timeDelta);
			}

			transform.worldTransform = transform.localTransform;
		}
	}

	virtual void Render(long frameNumber)
	{
	}
};

class NeMeshRendererSystem : public NeSystemBase
{
public:
	NeMeshRendererSystem(entt::registry* registry) : NeSystemBase(registry)
	{
	}

	virtual ~NeMeshRendererSystem()
	{
	}

	virtual void Update(long frameNumber, double timeDelta)
	{
	}

	virtual void Render(long frameNumber)
	{
		auto entities = this->GetRegistry()->view<NeMeshRendererComponent>();
		for (auto& entity : entities)
		{
			auto& transform = this->GetComponent<NeTransformComponent>(entity);
			auto& meshRenderer = this->GetComponent<NeMeshRendererComponent>(entity);
			for (auto& kvp : meshRenderer.renderInfoList)
			{
				auto material = kvp.first;
				auto meshes = kvp.second;
				if (material != nullptr)
				{
					material->Use();
					if (material->GetShader() != nullptr)
					{
						material->GetShader()->SetUniformMatrix4("transform", transform.worldTransform);
					}

					for (auto& mesh : meshes)
					{
						mesh->Draw();
					}
				}
			}
		}
	}
};

class NeAnimatorSystem : public NeSystemBase
{
public:
	NeAnimatorSystem(entt::registry* registry) : NeSystemBase(registry)
	{
	}

	virtual ~NeAnimatorSystem()
	{
	}

	virtual void Update(long frameNumber, double timeDelta)
	{
		auto entities = this->GetRegistry()->view<NeMeshRendererComponent>();

		for (auto& entity : entities)
		{
			auto& animator = this->GetComponent<NeAnimatorComponent>(entity);
			auto& transform = this->GetComponent<NeTransformComponent>(entity);
			animator.updateCallback(transform.localTransform, frameNumber, timeDelta);
		}
	}

	virtual void Render(long frameNumber)
	{
	}
};
