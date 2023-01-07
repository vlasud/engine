#include "engine.h"
#include <chrono>

// parse command line arguments
static void parse_args(int argc, char **argv)
{
	// TODO...
}

engine::Engine::Engine()
{
	// default window settings
	window.height = 600;
	window.width = 800;
	window.title = "Engine";
}

engine::Engine::~Engine()
{
}

void engine::Engine::Run(int argc, char** argv)
{
	if (!glfwInit())
		return;

	parse_args(argc, argv);

	window.glfwWindow = glfwCreateWindow(window.width, window.height, window.title, nullptr, nullptr);
	if (!window.glfwWindow)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window.glfwWindow);

	double deltaTime = 0;
	while (!glfwWindowShouldClose(window.glfwWindow))
	{
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		act(deltaTime);
		glfwSwapBuffers(window.glfwWindow);
		glfwPollEvents();
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
	}
}

void engine::Engine::AddContext(std::unique_ptr<Context> && context)
{
	contexts.push_back(std::move(context));
}

void engine::Engine::act(double delta_time)
{
	for (auto& context : contexts)
		context->Tick(delta_time);
}