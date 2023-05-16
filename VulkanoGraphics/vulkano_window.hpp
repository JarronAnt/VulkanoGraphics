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

		VulkanoWindow(const VulkanoWindow &) = delete;
		VulkanoWindow &operator=(const VulkanoWindow&) = delete;

		VkExtent2D getExtent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }
		void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
	};
}