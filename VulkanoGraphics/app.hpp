#pragma once
#include "vulkano_window.hpp"
#include "vulkano_pipeline.hpp"
#include "vulkano_device.hpp"

namespace Vulkano {

	class app
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();
	private:
			VulkanoWindow appWindow{ WIDTH, HEIGHT, "Vulkano" };
			VulkanoDevice vulkanoDevice{ appWindow };
			VulkanoPipeline vulkanoPipeline{vulkanoDevice, "simple_shader.vert.spv", "simple_shader.frag.spv", VulkanoPipeline::generateDefaultConfig(WIDTH,HEIGHT)};
	};

}

