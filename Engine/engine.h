#pragma once

#include "context.h"
#include "GLFW/glfw3.h"
#include <vector>
#include <memory>

namespace engine
{
	class Engine
	{
		struct Window
		{
			GLFWwindow* glfwWindow;
			int width;
			int height;
			const char* title;
		};
	
		std::vector<std::unique_ptr<Context>> contexts;
		
		void act(double);

	public:
		Engine();
		~Engine();

		void Run(int, char**);
		void AddContext(std::unique_ptr<Context> &&);

	private:
		Window window;
	};
}