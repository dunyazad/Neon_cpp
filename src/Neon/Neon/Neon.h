#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/Window.h>
#include <Neon/ECS.h>
#include <Neon/Graphics.h>

class Neon
{
public:
	Neon();
	~Neon();

	bool CreateNeonWindow(unsigned int width, unsigned int height, const char* title);
	void Frame();

	NeEntityBase* CreateEntity();

	template<typename T>
	vector<NeComponentBase*> GetComponents()
	{
		if (this->components.count(typeid(T).name()) != 0)
		{
			return this->components[typeid(T).name()];
		}
		else
		{
			return vector<NeComponentBase*>();
		}
	}

	template<typename T>
	T* CreateComponent()
	{
		auto component = new T();
		this->components[typeid(T).name()].push_back(component);
		return component;
	}

	inline NeWindow* GetWindow() const { return this->window; }

private:
	NeWindow* window = nullptr;

	map<string, vector<NeComponentBase*>> components;
	vector<NeEntityBase*> entities;
	vector<NeSystemBase*> systems;

	chrono::system_clock::time_point lastTime;
	double accumulatedTime = 0.0;
	string fps;
	string msPerFrame;
	long frameNumber = 0;
	unsigned int frameCounter = 0;
};
