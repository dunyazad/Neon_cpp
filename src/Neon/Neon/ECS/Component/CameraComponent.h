#pragma once

#include <Neon/NeonCommon.h>
#include <Neon/ECS/Component/ComponentBase.h>

class NeCameraComponent : public NeComponentBase
{
public:
	NeCameraComponent();
	virtual ~NeCameraComponent();

	inline const glm::mat4& GetProjectionMatrix() const { return this->projectionMatrix; }
	inline void SetProjectionMatrix(const glm::mat4& matrix) { this->projectionMatrix = matrix; }

	inline const glm::mat4& GetViewMatrix() const { return this->viewMatrix; }
	inline void SetViewMatrix(const glm::mat4& matrix) { this->viewMatrix = matrix; }

protected:
	glm::mat4 projectionMatrix = glm::identity<glm::mat4>();
	glm::mat4 viewMatrix = glm::identity<glm::mat4>();
};
