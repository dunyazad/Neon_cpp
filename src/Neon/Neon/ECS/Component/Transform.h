#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/ECS/Component/ComponentBase.h>

class NeTransformComponent : public NeComponentBase
{
public:
	NeTransformComponent();
	virtual ~NeTransformComponent();

	void AttachChild(NeTransformComponent* child);
	void DetachChild(NeTransformComponent* child);

	inline const glm::mat4& GetLocalTransform() const { return this->localTransform; }
	inline void SetLocalMatrix(const glm::mat4& m) { this->localTransform = m; this->SetDirty(true); }

	inline const glm::mat4& GetWorldTransform() const { return this->worldTransform; }
	inline void SetWorldMatrix(const glm::mat4& m) { this->worldTransform = m; this->SetDirty(true); }

	inline NeTransformComponent* GetParent() const { return this->parent; }
	inline const set<NeTransformComponent*>& GetChildren() const { return this->children; }

protected:
	NeTransformComponent* parent = nullptr;
	set<NeTransformComponent*> children;
	glm::mat4 localTransform = glm::identity<glm::mat4>();
	glm::mat4 worldTransform = glm::identity<glm::mat4>();
};
