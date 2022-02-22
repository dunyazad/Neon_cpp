#include <Neon/Neon.h>

Neon::Neon()
{
	glfwInit();

	std::cout << "Initializing Freetype..." << std::flush;

	FT_Library ft;

	if (FT_Init_FreeType(&ft)) {
		std::cout << "FAILED" << std::endl;
		return;
	}

	std::cout << "OK" << std::endl;

	auto animatorSystem = new NeAnimatorSystem(this);
	this->systems.push_back(animatorSystem);

	auto transformSystem = new NeTransformSystem(this);
	this->systems.push_back(transformSystem);

	auto meshSystem = new NeMeshSystem(this);
	this->systems.push_back(meshSystem);

	auto meshRendererSystem = new NeMeshRendererSystem(this);
	this->systems.push_back(meshRendererSystem);
}

Neon::~Neon()
{
	for (auto& system : this->systems)
	{
		if (system != nullptr)
		{
			delete system;
		}
	}
	this->systems.clear();

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


	for (auto& system : this->systems)
	{
		system->Update(this->frameNumber, timeDelta);
	}

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto& system : this->systems)
	{
		system->Render(this->frameNumber);
	}

	this->frameNumber++;
}

NeEntityBase* Neon::CreateEntity()
{
	this->registry.create();

	auto entity = new NeEntityBase();
	this->entities.push_back(entity);
	return entity;
}
