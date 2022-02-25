#pragma once
#include <Neon/Graphics/Mesh.h>

NeMesh::NeMesh()
{
}

NeMesh::~NeMesh()
{
}

void NeMesh::Refresh()
{
	this->vao.Bind();

	if (this->vertexBuffer.Size() > 0)
	{
		this->vertexBuffer.Refresh(0);
	}

	if (this->colorBuffer.Size() > 0)
	{
		this->colorBuffer.Refresh(1);
	}

	if (this->texCoordBuffer.Size() > 0)
	{
		this->texCoordBuffer.Refresh(2);
	}

	if (this->indexBuffer.Size() > 0)
	{
		this->indexBuffer.Refresh((GLuint)-1);
	}
}

void NeMesh::Draw()
{
	this->vao.Bind();
	if (this->indexBuffer.Size() > 0)
	{
		glDrawElements(GL_TRIANGLES, (GLsizei)this->indexBuffer.Size(), GL_UNSIGNED_INT, 0);
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, (GLsizei)this->vertexBuffer.Size());
	}
}
