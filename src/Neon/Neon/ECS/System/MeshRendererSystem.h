#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/ECS/System/SystemBase.h>

class Neon;
class NeComponentBase;

class NeMeshRendererSystem : public NeSystemBase
{
public:
	NeMeshRendererSystem(Neon* neon);
	virtual ~NeMeshRendererSystem();

	virtual void Update(long frameNumber, double timeDelta);
	virtual void Render(long frameNumber);
private:

};
