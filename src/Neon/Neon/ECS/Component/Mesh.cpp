#include <Neon/ECS/Component/Mesh.h>
#include <Neon/Graphics/Buffer.hpp>

NeMeshComponent::NeMeshComponent()
	: NeComponentBase()
{
	this->vao = new NeVAO();

	this->vertexBuffer = new NeBuffer<glm::vec3>(GL_ARRAY_BUFFER);
	this->colorBuffer = new NeBuffer<glm::vec4>(GL_ARRAY_BUFFER);
	this->texCoordBuffer = new NeBuffer<glm::vec2>(GL_ARRAY_BUFFER);
	this->indexBuffer = new NeBuffer<GLuint>(GL_ELEMENT_ARRAY_BUFFER);
}

NeMeshComponent::~NeMeshComponent()
{
	if (this->vertexBuffer != nullptr)
	{
		delete this->vertexBuffer;
		this->vertexBuffer = nullptr;
	}

	if (this->colorBuffer != nullptr)
	{
		delete this->colorBuffer;
		this->colorBuffer = nullptr;
	}

	if (this->texCoordBuffer != nullptr)
	{
		delete this->texCoordBuffer;
		this->texCoordBuffer = nullptr;
	}

	if (this->indexBuffer != nullptr)
	{
		delete this->indexBuffer;
		this->indexBuffer = nullptr;
	}

	if (this->vao != nullptr)
	{
		delete this->vao;
		this->vao = nullptr;
	}
}

void NeMeshComponent::Refresh()
{
	this->vao->Bind();

	if (this->vertexBuffer != nullptr)
	{
		this->vertexBuffer->Refresh(0);
	}

	if (this->colorBuffer != nullptr)
	{
		this->colorBuffer->Refresh(1);
	}

	if (this->texCoordBuffer != nullptr)
	{
		this->texCoordBuffer->Refresh(2);
	}

	if (this->indexBuffer != nullptr)
	{
		this->indexBuffer->Refresh((GLuint) - 1);
	}
}

void NeMeshComponent::Draw()
{
	this->vao->Bind();
	glDrawElements(GL_TRIANGLES, (GLsizei)this->indexBuffer->Size(), GL_UNSIGNED_INT, 0);
}
