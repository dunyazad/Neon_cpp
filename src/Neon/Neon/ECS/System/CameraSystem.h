#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/ECS/System/SystemBase.h>

class Neon;
class NeComponentBase;

class NeCameraSystem : public NeSystemBase
{
public:
	NeCameraSystem(Neon* neon);
	virtual ~NeCameraSystem();

	virtual void Update(long frameNumber, double timeDelta);
	virtual void Render(long frameNumber);
private:

};
