#pragma once

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include <string>

namespace Vulkano {
	
	
	class VulkanoWindow {
	private:
		GLFWwindow* window;
		const int width;
		const int height;
		std::string name;

		void initWindow();

	public:
		VulkanoWindow(int w, int h, std::string name);
		bool shouldClose() { return glfwWindowShouldClose(window); };
		~VulkanoWindow();
	};
}