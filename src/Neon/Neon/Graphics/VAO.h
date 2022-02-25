#pragma once

#include <Neon/NeonCommon.h>

class NeVAO
{
public:
	NeVAO()
	{
		glGenVertexArrays(1, &this->arrayID);
	}

	~NeVAO()
	{
		glGenVertexArrays(1, &this->arrayID);
	}

	void Bind()
	{
		glBindVertexArray(this->arrayID);
	}

	void Unbind()
	{
		glBindVertexArray(0);
	}

protected:
	unsigned int arrayID = UINT_MAX;
};
