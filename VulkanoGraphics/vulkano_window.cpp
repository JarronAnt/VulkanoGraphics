#include "vulkano_window.hpp"
#include <stdexcept>

namespace Vulkano {

	VulkanoWindow::VulkanoWindow(int w, int h, std::string name):width{w}, height{h},name{name}
	{
		initWindow();
	}

	VulkanoWindow::~VulkanoWindow() {
		glfwDestroyWindow(window);

		glfwTerminate();
	}

	void VulkanoWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("failed to create window surface");
		}
	}

	void VulkanoWindow::initWindow() {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

	}
}