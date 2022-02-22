#pragma once

#include <Neon/NeonCommon.h>

template<typename T>
class NeBuffer;
class NeVAO;

class NeComponentBase
{
public:
	NeComponentBase();
	virtual ~NeComponentBase();

	inline string GetComponentType() { return this->componentType; }

	inline bool IsDirty() const { return this->dirty; }
	inline void SetDirty(bool isDirty) { this->dirty = isDirty; }

	template<typename T>
	T* As() { return dynamic_cast<T*>(this); }

private:
	string componentType;
	bool dirty = true;
};
