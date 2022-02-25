#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/Window.h>
#include <Neon/Graphics.h>

#include <Neon/Component.h>
#include <Neon/System.h>

class Neon
{
public:
	Neon();
	~Neon();

	bool CreateNeonWindow(unsigned int width, unsigned int height, const char* title);
	void OnInitialize();
	void OnTerminate();
	void Frame();

	NeEntity CreateEntity(const string& name);

	NeMesh* GetOrCreateMesh(const string& name);
	NeShader* GetOrCreateShader(const string& name);
	NeTexture* GetOrCreateTexture(const string& name);
	NeMaterial* GetOrCreateMaterial(const string& name);

	template <typename T, typename... Args>
	T& CreateComponent(NeEntity entity, Args&&... args)
	{
		return this->registry.emplace<T>(entity, std::forward<Args>(args)...);
	}

	template<typename T>
	T& GetComponents(NeEntity entity)
	{
		return this->registry.get<T>(entity);
	}

	inline NeWindow* GetWindow() const { return this->window; }
	inline entt::registry& GetRegistry() { return this->registry; }

private:
	NeWindow* window = nullptr;

	entt::registry registry;
	NeTransformSystem transformSystem;
	NeAnimatorSystem animatorSystem;
	NeMeshRendererSystem meshRendererSystem;

	map<string, NeMesh*> meshes;
	map<string, NeShader*> shaders;
	map<string, NeTexture*> textures;
	map<string, NeMaterial*> materials;

	chrono::system_clock::time_point lastTime;
	double accumulatedTime = 0.0;
	string fps;
	string msPerFrame;
	long frameNumber = 0;
	unsigned int frameCounter = 0;
};
