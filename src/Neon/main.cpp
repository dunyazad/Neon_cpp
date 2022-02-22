#include <Neon/Neon.h>

int main () {
	auto neon = Neon();
	neon.CreateNeonWindow(800, 600, "Neon");

	// Use this to disable VSync (not advized)
	//glfwSwapInterval(0);


	{
		auto ent = neon.CreateEntity();

		auto transform = neon.CreateComponent<NeTransformComponent>();
		ent->AddComponent(transform);

		auto animator = neon.CreateComponent<NeAnimatorComponent>();
		animator->SetTransform(transform);
		animator->AddUpdateCallback([](NeTransformComponent* transform, long frameNumber, double timeDelta) {
			auto m = transform->GetLocalTransform();
			m = glm::rotate(m, glm::radians((float)timeDelta) * 0.1f, glm::vec3(0, 0, 1));
			transform->SetLocalMatrix(m);
			});

		auto mesh = neon.CreateComponent<NeMeshComponent>();
		ent->AddComponent(mesh);
		{
			mesh->GetVertexBuffer()->AppendData(glm::vec3(-0.05f, -0.05f, 0.0f));
			mesh->GetVertexBuffer()->AppendData(glm::vec3(0.0f, -0.05f, 0.0f));
			mesh->GetVertexBuffer()->AppendData(glm::vec3(-0.05f, 0.05f, 0.0f));
			mesh->GetVertexBuffer()->AppendData(glm::vec3(0.0f, 0.05f, 0.0f));

			mesh->GetVertexBuffer()->AppendData(glm::vec3(0.0f, -0.05f, 0.0f));
			mesh->GetVertexBuffer()->AppendData(glm::vec3(0.05f, -0.05f, 0.0f));
			mesh->GetVertexBuffer()->AppendData(glm::vec3(0.0f, 0.05f, 0.0f));
			mesh->GetVertexBuffer()->AppendData(glm::vec3(0.05f, 0.05f, 0.0f));

			mesh->GetColorBuffer()->AppendData(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
			mesh->GetColorBuffer()->AppendData(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
			mesh->GetColorBuffer()->AppendData(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
			mesh->GetColorBuffer()->AppendData(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

			mesh->GetColorBuffer()->AppendData(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
			mesh->GetColorBuffer()->AppendData(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
			mesh->GetColorBuffer()->AppendData(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
			mesh->GetColorBuffer()->AppendData(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

			mesh->GetTexCoordBuffer()->AppendData(glm::vec2(0.0f, 0.0f));
			mesh->GetTexCoordBuffer()->AppendData(glm::vec2(0.5f, 0.0f));
			mesh->GetTexCoordBuffer()->AppendData(glm::vec2(0.0f, 0.5f));
			mesh->GetTexCoordBuffer()->AppendData(glm::vec2(0.5f, 0.5f));

			mesh->GetTexCoordBuffer()->AppendData(glm::vec2(0.0f, 0.0f));
			mesh->GetTexCoordBuffer()->AppendData(glm::vec2(0.5f, 0.0f));
			mesh->GetTexCoordBuffer()->AppendData(glm::vec2(0.0f, 0.5f));
			mesh->GetTexCoordBuffer()->AppendData(glm::vec2(0.5f, 0.5f));

			mesh->GetIndexBuffer()->AppendData(0);
			mesh->GetIndexBuffer()->AppendData(1);
			mesh->GetIndexBuffer()->AppendData(2);
			mesh->GetIndexBuffer()->AppendData(3);
			mesh->GetIndexBuffer()->AppendData(2);
			mesh->GetIndexBuffer()->AppendData(1);

			mesh->GetIndexBuffer()->AppendData(4);
			mesh->GetIndexBuffer()->AppendData(5);
			mesh->GetIndexBuffer()->AppendData(6);
			mesh->GetIndexBuffer()->AppendData(7);
			mesh->GetIndexBuffer()->AppendData(6);
			mesh->GetIndexBuffer()->AppendData(5);

			mesh->Refresh();
		}

		auto shader = neon.CreateComponent<NeShaderComponent>();
		ent->AddComponent(shader);
		shader->SetVertexShaderFile("../../res/shaders/texture/texture.vs");
		shader->SetFragmentShaderFile("../../res/shaders/texture/texture.fs");
		if (shader->Build() == false)
		{
			SPDLOG_CRITICAL("Failed to build shader");
		}

		auto texture = neon.CreateComponent<NeTextureComponent>();
		ent->AddComponent(texture);
		texture->LoadFromFile("../../res/images/grid.png", 4167, 4167);

		auto material = neon.CreateComponent<NeMaterialComponent>();
		ent->AddComponent(material);
		material->SetShader(shader);
		material->SetTexture(texture);

		auto meshRenderer = neon.CreateComponent<NeMeshRendererComponent>();
		ent->AddComponent(meshRenderer);
		meshRenderer->SetTransform(transform);
		meshRenderer->SetMesh(mesh);
		meshRenderer->SetMaterial(material);
	}
	{
		auto ent = neon.CreateEntity();

		auto transform = neon.CreateComponent<NeTransformComponent>();
		ent->AddComponent(transform);
		glm::mat4 localMatrix = glm::identity<glm::mat4>();
		localMatrix = glm::translate(localMatrix, glm::vec3(0.0f, 0.1f, 0.0f));
		transform->SetLocalMatrix(localMatrix);

		auto animator = neon.CreateComponent<NeAnimatorComponent>();
		animator->SetTransform(transform);
		animator->AddUpdateCallback([](NeTransformComponent* transform, long frameNumber, double timeDelta) {
			static double elapsed = 0.0f;
			elapsed += timeDelta;
			glm::mat4 m = glm::identity<glm::mat4>();
			m = glm::translate(m, glm::vec3(sinf(glm::radians(elapsed * 0.02f)), 0, 0));
			transform->SetLocalMatrix(m);
			});

		auto mesh = neon.CreateComponent<NeMeshComponent>();
		ent->AddComponent(mesh);
		{
			mesh->GetVertexBuffer()->AppendData(glm::vec3(-0.05f, -0.05f, 0.0f));
			mesh->GetVertexBuffer()->AppendData(glm::vec3(0.05f, -0.05f, 0.0f));
			mesh->GetVertexBuffer()->AppendData(glm::vec3(0.0f, 0.05f, 0.0f));

			mesh->GetColorBuffer()->AppendData(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
			mesh->GetColorBuffer()->AppendData(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
			mesh->GetColorBuffer()->AppendData(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

			mesh->GetIndexBuffer()->AppendData(0);
			mesh->GetIndexBuffer()->AppendData(1);
			mesh->GetIndexBuffer()->AppendData(2);

			mesh->Refresh();
		}

		const char* vertexShaderSource = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout (location = 1) in vec4 aCol;\n"
			"uniform mat4 transform;"
			"out vec4 vCol;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"	vCol = aCol;\n"
			"}\0";
		const char* fragmentShaderSource = "#version 330 core\n"
			"in vec4 vCol;\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(0.3f, 0.5f, 0.7f, 1.0f);\n"
			//"   FragColor = vCol;\n"
			"}\n\0";

		auto shader = neon.CreateComponent<NeShaderComponent>();
		ent->AddComponent(shader);
		shader->SetVertexShaderCode(vertexShaderSource);
		shader->SetFragmentShaderCode(fragmentShaderSource);
		if (shader->Build() == false)
		{
			SPDLOG_CRITICAL("Failed to build shader");
		}

		auto material = neon.CreateComponent<NeMaterialComponent>();
		ent->AddComponent(material);
		material->SetShader(shader);

		auto meshRenderer = neon.CreateComponent<NeMeshRendererComponent>();
		ent->AddComponent(meshRenderer);
		meshRenderer->SetTransform(transform);
		meshRenderer->SetMesh(mesh);
		meshRenderer->SetMaterial(material);
	}

//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);







	neon.GetWindow()->RunLoop();

	return 0;
}
