#include "app.hpp"

namespace Vulkano {
	void app::run() {
		while (!appWindow.shouldClose()) {
			glfwPollEvents();
		}
	}
}