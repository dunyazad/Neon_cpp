#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/ECS/Component/ComponentBase.h>

class NeTransformComponent;
class NeMeshComponent;
class NeMaterialComponent;

class NeMeshRendererComponent : public NeComponentBase
{
public:
	NeMeshRendererComponent();
	virtual ~NeMeshRendererComponent();

	inline NeTransformComponent* GetTransform() const { return this->transformComponent; }
	inline void SetTransform(NeTransformComponent* transform) { this->transformComponent = transform; }
	
	inline NeMeshComponent* GetMesh() const { return this->meshComponent; }
	inline void SetMesh(NeMeshComponent* mesh) { this->meshComponent = mesh; }

	inline NeMaterialComponent* GetMaterial() const { return this->materialComponent; }
	inline void SetMaterial(NeMaterialComponent* material) { this->materialComponent = material; }

private:
	NeTransformComponent* transformComponent = nullptr;
	NeMeshComponent* meshComponent = nullptr;
	NeMaterialComponent* materialComponent = nullptr;
};
