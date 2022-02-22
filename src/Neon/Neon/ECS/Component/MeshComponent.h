#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/ECS/Component/ComponentBase.h>

class NeMeshComponent : public NeComponentBase
{
public:
	NeMeshComponent();
	virtual ~NeMeshComponent();

	void Refresh();

	void Draw();

	inline NeBuffer<glm::vec3>* GetVertexBuffer() const { return this->vertexBuffer; }
	inline NeBuffer<glm::vec4>* GetColorBuffer() const { return this->colorBuffer; }
	inline NeBuffer<glm::vec2>* GetTexCoordBuffer() const { return this->texCoordBuffer; }
	inline NeBuffer<GLuint>* GetIndexBuffer() const { return this->indexBuffer; }

private:
	NeVAO* vao = nullptr;

	NeBuffer<glm::vec3>* vertexBuffer;
	NeBuffer<glm::vec4>* colorBuffer;
	NeBuffer<glm::vec2>* texCoordBuffer;
	NeBuffer<GLuint>* indexBuffer;
};
