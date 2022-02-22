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

class NeTransformSystem : public NeSystemBase
{
public:
	NeTransformSystem(Neon* neon);
	virtual ~NeTransformSystem();

	virtual void Update(long frameNumber, double timeDelta);
	virtual void Render(long frameNumber);
private:

};

class NeMeshSystem : public NeSystemBase
{
public:
	NeMeshSystem(Neon* neon);
	virtual ~NeMeshSystem();

	virtual void Update(long frameNumber, double timeDelta);
	virtual void Render(long frameNumber);
private:

};

class NeMeshRendererSystem : public NeSystemBase
{
public:
	NeMeshRendererSystem(Neon* neon);
	virtual ~NeMeshRendererSystem();

	virtual void Update(long frameNumber, double timeDelta);
	virtual void Render(long frameNumber);
private:

};

class NeAnimatorSystem : public NeSystemBase
{
public:
	NeAnimatorSystem(Neon* neon);
	virtual ~NeAnimatorSystem();

	virtual void Update(long frameNumber, double timeDelta);
	virtual void Render(long frameNumber);
private:

};
