#pragma once
#include <Neon/NeonCommon.h>
#include <Neon/Graphics/Buffer.hpp>
#include <Neon/Graphics/VAO.h>

class NeMesh
{
public:
	NeMesh();

	~NeMesh();

	void Refresh();

	void Draw();
	
	inline bool IsDirty() const { return this->dirty; }
	inline void SetDirty() { this->dirty = true; }

	inline NeBuffer<glm::vec3>& GetVertexBuffer() { return this->vertexBuffer; }
	inline NeBuffer<glm::vec4>& GetColorBuffer() { return this->colorBuffer; }
	inline NeBuffer<glm::vec2>& GetTexCoordBuffer() { return this->texCoordBuffer; }
	inline NeBuffer<GLuint>& GetIndexBuffer() { return this->indexBuffer; }
	
private:
	bool dirty = true;
	NeVAO vao;

	NeBuffer<glm::vec3> vertexBuffer = NeBuffer<glm::vec3>(GL_ARRAY_BUFFER, GL_FLOAT);
	NeBuffer<glm::vec4> colorBuffer = NeBuffer<glm::vec4>(GL_ARRAY_BUFFER, GL_FLOAT);
	NeBuffer<glm::vec2> texCoordBuffer = NeBuffer<glm::vec2>(GL_ARRAY_BUFFER, GL_FLOAT);
	NeBuffer<GLuint> indexBuffer = NeBuffer<GLuint>(GL_ELEMENT_ARRAY_BUFFER, GL_UNSIGNED_INT);
};
