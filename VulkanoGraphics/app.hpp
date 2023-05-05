#pragma once
#include "vulkano_window.hpp"

namespace Vulkano {

	class app
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();
	private:
			VulkanoWindow appWindow{ WIDTH, HEIGHT, "Vulkano" };
	};

}

