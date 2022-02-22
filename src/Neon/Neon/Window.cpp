#include <Neon/Window.h>
#include <Neon/Neon.h>

NeWindow::NeWindow(Neon* neon)
	: neon(neon)
{
}

NeWindow::~NeWindow()
{
	DestroyWindow();
}

bool NeWindow::Create(unsigned int width, unsigned int height, const char* title) {
	DestroyWindow();
	this->windowHandle = glfwCreateWindow(width, height, title, nullptr, nullptr);

	if (!this->windowHandle) {
		return false;
	}

	glfwMakeContextCurrent(this->windowHandle);


	std::cout << "Initializing Imgui..." << std::flush;

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(this->windowHandle, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	std::cout << "OK" << std::endl;



	return true;
}

void NeWindow::RunLoop()
{
	bool demoWindow = true;

	while (!glfwWindowShouldClose(this->windowHandle)) {
		this->neon->Frame();

		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();

		ImGui::NewFrame();
		ImGui::ShowDemoWindow(&demoWindow);
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		int display_w, display_h;
		glfwGetFramebufferSize(this->windowHandle, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glfwSwapBuffers(this->windowHandle);
	}
}

void NeWindow::RunLoop(std::function<void()> onUpdate)
{
	bool demoWindow = true;

	while (!glfwWindowShouldClose(this->windowHandle)) {
		glfwPollEvents();

		this->neon->Frame();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		

		onUpdate();


		ImGui::NewFrame();
		ImGui::ShowDemoWindow(&demoWindow);
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		int display_w, display_h;
		glfwGetFramebufferSize(this->windowHandle, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glfwSwapBuffers(this->windowHandle);
	}
}

void NeWindow::DestroyWindow() {
	if (this->windowHandle) {
		glfwDestroyWindow(this->windowHandle);
		this->windowHandle = nullptr;
	}
}
