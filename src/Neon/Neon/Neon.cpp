#include <Neon/Neon.h>

Neon::Neon()
	: transformSystem(&registry), animatorSystem(&registry), meshRendererSystem(&registry)
{
	glfwInit();

	std::cout << "Initializing Freetype..." << std::flush;

	FT_Library ft;

	if (FT_Init_FreeType(&ft)) {
		std::cout << "FAILED" << std::endl;
		return;
	}

	std::cout << "OK" << std::endl;
}

Neon::~Neon()
{
	this->registry.clear();

	glfwTerminate();
}

bool Neon::CreateNeonWindow(unsigned int width, unsigned int height, const char* title)
{
	this->window = new NeWindow(this);
	if (this->window->Create(width, height, title) == false)
	{
		return false;
	}

	std::cout << "Initializing GLAD..." << std::flush;

	auto gladAddress = glfwGetProcAddress;
	if (!gladLoadGLLoader((GLADloadproc)gladAddress)) {
		std::cout << "FAILED" << std::endl;
		return false;
	}
	std::cout << "OK" << std::endl;

	lastTime = chrono::system_clock::now();
	
	return true;
}

void Neon::OnInitialize()
{
}

void Neon::OnTerminate()
{
}

void Neon::Frame()
{
	this->frameCounter++;

	auto now = chrono::system_clock::now();
	auto delta = now - lastTime;
	lastTime = now;

	auto timeDelta = (double)(chrono::duration_cast<std::chrono::milliseconds>(delta).count());
	accumulatedTime += timeDelta;
	if (accumulatedTime >= 1000)
	{
		// Creates new title
		this->fps = std::to_string(((double)this->frameCounter / accumulatedTime) * 1000.0);
		this->msPerFrame = std::to_string((accumulatedTime / (double)this->frameCounter));

		// Resets times and counter
		this->frameCounter = 0;

		accumulatedTime = 0.0;
	}
	string newTitle = "[" + to_string(frameNumber) + "] Neon - " + this->fps + " FPS / " + this->msPerFrame + " ms per frame / " + to_string(timeDelta) + " ms";
	glfwSetWindowTitle(GetWindow()->GetWindowHandle(), newTitle.c_str());


	//this->animatorSystem.Update(this->frameNumber, timeDelta);
	this->transformSystem.Update(this->frameNumber, timeDelta);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	this->meshRendererSystem.Render(this->frameNumber);

	//for (auto& system : this->systems)
	//{
	//	system->Render(this->frameNumber);
	//}

	this->frameNumber++;
}

NeEntity Neon::CreateEntity(const string& name)
{
	auto entity = this->registry.create();
	this->registry.emplace<NeNameComponent>(entity, name);
	return entity;
}

NeMesh* Neon::GetOrCreateMesh(const string& name)
{
	if (this->meshes.count(name) != 0)
	{
		return this->meshes[name];
	}
	else
	{
		auto mesh = new NeMesh();
		this->meshes[name] = mesh;
		return mesh;
	}
}

NeShader* Neon::GetOrCreateShader(const string& name)
{
	if (this->shaders.count(name) != 0)
	{
		return this->shaders[name];
	}
	else
	{
		auto shader = new NeShader();
		this->shaders[name] = shader;
		return shader;
	}
}

NeTexture* Neon::GetOrCreateTexture(const string& name)
{
	if (this->textures.count(name) != 0)
	{
		return this->textures[name];
	}
	else
	{
		auto texture = new NeTexture();
		this->textures[name] = texture;
		return texture;
	}
}

NeMaterial* Neon::GetOrCreateMaterial(const string& name)
{
	if (this->materials.count(name) != 0)
	{
		return this->materials[name];
	}
	else
	{
		auto material = new NeMaterial();
		this->materials[name] = material;
		return material;
	}
}
