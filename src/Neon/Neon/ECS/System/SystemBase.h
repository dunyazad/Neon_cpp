#pragma once

#include <Neon/NeonCommon.h>

class Neon;
class NeComponentBase;

class NeSystemBase
{
public:
	NeSystemBase(Neon* neon);
	virtual ~NeSystemBase();

	virtual void Update(long frameNumber, double timeDelta) = 0;
	virtual void Render(long frameNumber) = 0;
protected:
	Neon* neon = nullptr;
};
