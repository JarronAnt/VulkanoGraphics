#include "vulkano_window.hpp"


namespace Vulkano {

	VulkanoWindow::VulkanoWindow(int w, int h, std::string name):width{w}, height{h},name{name}
	{
		initWindow();
	}

	VulkanoWindow::~VulkanoWindow() {
		glfwDestroyWindow(window);

		glfwTerminate();
	}

	void VulkanoWindow::initWindow() {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

	}
}