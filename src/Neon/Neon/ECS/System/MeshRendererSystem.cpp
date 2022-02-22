#include <Neon/ECS/System/MeshRendererSystem.h>
#include <Neon/Neon.h>

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
