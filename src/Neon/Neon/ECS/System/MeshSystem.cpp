#include <Neon/ECS/System/MeshSystem.h>

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
