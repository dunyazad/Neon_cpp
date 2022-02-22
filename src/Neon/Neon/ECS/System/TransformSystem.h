#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/ECS/System/SystemBase.h>

class Neon;
class NeComponentBase;

class NeTransformSystem : public NeSystemBase
{
public:
	NeTransformSystem(Neon* neon);
	virtual ~NeTransformSystem();

	virtual void Update(long frameNumber, double timeDelta);
	virtual void Render(long frameNumber);
private:

};
