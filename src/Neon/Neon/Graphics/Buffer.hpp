#pragma once

#include <Neon/NeonCommon.h>

template <typename T>
class NeBuffer
{
public:
	// bufferTarget : GL_ARRAY_BUFFER or GL_ELEMENT_ARRAY_BUFFER
	// elementType : GL_BYTE or GL_UNSIGNED_BYTE or GL_SHORT or GL_UNSIGNED_SHORT or GL_INT or GL_UNSIGNED_INT of GL_FLOAT
	NeBuffer(GLsizei bufferTarget = GL_ARRAY_BUFFER, GLenum elementType = GL_FLOAT)
		: bufferTarget(bufferTarget), elementType(elementType)
	{
		switch (elementType)
		{
		case GL_BYTE:
			this->elementSize = sizeof(T) / sizeof(GLbyte);
			break;
		case GL_UNSIGNED_BYTE:
			this->elementSize = sizeof(T) / sizeof(GLubyte);
			break;
		case GL_SHORT:
			this->elementSize = sizeof(T) / sizeof(GLshort);
			break;
		case GL_UNSIGNED_SHORT:
			this->elementSize = sizeof(T) / sizeof(GLushort);
			break;
		case GL_INT:
			this->elementSize = sizeof(T) / sizeof(GLint);
			break;
		case GL_UNSIGNED_INT:
			this->elementSize = sizeof(T) / sizeof(GLuint);
			break;
		case GL_FLOAT:
			this->elementSize = sizeof(T) / sizeof(GLfloat);
			break;
		default:
			break;
		}

		glGenBuffers(1, &this->bufferID);
	}

	~NeBuffer()
	{
		glDeleteBuffers(1, &this->bufferID);
	}

	void Bind()
	{
		glBindBuffer(this->bufferTarget, this->bufferID);
	}

	void Unbind()
	{
		glBindBuffer(this->bufferTarget, 0);
	}

	void Refresh(GLuint attributeIndex)
	{
		this->Bind();

		glBufferData(this->bufferTarget, sizeof(T) * this->bufferData.size(), this->bufferData.data(), GL_STATIC_DRAW);

		if (bufferTarget == GL_ARRAY_BUFFER)
		{
			glVertexAttribPointer(attributeIndex, this->elementSize, elementType, GL_FALSE, sizeof(T), (void*)0);
			glEnableVertexAttribArray(attributeIndex);
		}
	}

	void AppendData(const T& data)
	{
		this->bufferData.push_back(data);
	}

	void AppendData(const vector<T>& datas)
	{
		this->bufferData.insert(this->bufferData.end(), datas.begin(), datas.end());
	}

	size_t Size()
	{
		return this->bufferData.size();
	}

protected:
	unsigned int bufferID = UINT_MAX;
	GLsizei bufferTarget = GL_ARRAY_BUFFER;
	GLenum elementType = GL_FLOAT;
	GLint elementSize = 0;
	vector<T> bufferData;
};

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
