#pragma once

#include <Neon/NeonCommon.h>

class NeComponentBase;

class NeEntityBase
{
public:
	NeEntityBase();
	~NeEntityBase();

	void OnUpdate(function<void(double)> callback);
	void OnRender(function<void(void)> callback);

	const list<NeComponentBase*>& GetComponents();
	void AddComponent(NeComponentBase* component);
	void RemoveComponent(NeComponentBase* component);

private:
	list<NeComponentBase*> components;
	vector<function<void(double)>> updateCallbacks;
	vector<function<void(void)>> renderCallbacks;
};
