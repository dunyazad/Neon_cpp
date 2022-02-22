#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/ECS/Component/ComponentBase.h>

class NeTransformComponent;

class NeAnimatorComponent : public NeComponentBase
{
public:
	NeAnimatorComponent();
	virtual ~NeAnimatorComponent();

	inline NeTransformComponent* GetTransform() const { return this->transformComponent; }
	inline void SetTransform(NeTransformComponent* transform) { this->transformComponent = transform; }

	inline void AddUpdateCallback(function<void(NeTransformComponent*, long, double)> callback) { this->updateCallbacks.push_back(callback); }
	
	inline const vector<function<void(NeTransformComponent*, long, double)>>& GetUpdateCallbacks() const { return this->updateCallbacks; }

protected:
	NeTransformComponent* transformComponent = nullptr;
	vector<function<void(NeTransformComponent*, long, double)>> updateCallbacks;
};
