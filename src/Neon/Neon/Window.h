#pragma once

#include <Neon/NeonCommon.h>

class Neon;

class NeWindow
{
public:
	NeWindow(Neon* neon);
	~NeWindow();

	bool Create(unsigned int width, unsigned int height, const char* title);
	void RunLoop();
	void RunLoop(std::function<void()> onUpdate);
	void DestroyWindow();

	inline GLFWwindow* GetWindowHandle() const { return windowHandle; }

protected:
	Neon* neon = nullptr;
	GLFWwindow* windowHandle = nullptr;

};
