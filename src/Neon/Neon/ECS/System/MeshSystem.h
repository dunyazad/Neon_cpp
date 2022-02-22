#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/ECS/System/SystemBase.h>

class Neon;
class NeComponentBase;

class NeMeshSystem : public NeSystemBase
{
public:
	NeMeshSystem(Neon* neon);
	virtual ~NeMeshSystem();

	virtual void Update(long frameNumber, double timeDelta);
	virtual void Render(long frameNumber);
private:

};
