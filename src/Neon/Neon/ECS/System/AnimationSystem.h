#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/ECS/System/SystemBase.h>

class Neon;
class NeComponentBase;

class NeAnimatorSystem : public NeSystemBase
{
public:
	NeAnimatorSystem(Neon* neon);
	virtual ~NeAnimatorSystem();

	virtual void Update(long frameNumber, double timeDelta);
	virtual void Render(long frameNumber);
private:

};
