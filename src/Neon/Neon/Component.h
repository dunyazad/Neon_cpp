#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/Graphics.h>

struct NeNameComponent
{
	string name;
};

struct NeTransformComponent
{
	bool dirty = true;
	NeTransformComponent* parent = nullptr;
	set<NeTransformComponent*> children;
	glm::mat4 localTransform = glm::identity<glm::mat4>();
	glm::mat4 worldTransform = glm::identity<glm::mat4>();
};

struct NeMaterialComponent
{
	NeShader* shader = nullptr;
	NeTexture* texture = nullptr;
};

struct NeMeshRendererComponent
{
	map<NeMaterial*, vector<NeMesh*>> renderInfoList;
};

struct NeAnimatorComponent
{
	typedef function<void(glm::mat4&, long, double)> Callback;
	Callback updateCallback;
};
