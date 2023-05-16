#pragma once
#include "vulkano_window.hpp"
#include "vulkano_pipeline.hpp"
#include "vulkano_device.hpp"
#include "vulkano_swap_chain.hpp"
#include <memory>
#include <vector>

namespace Vulkano {

	class app
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		app();
		~app();

		app(const app&) = delete;
		app& operator=(const app&) = delete;

		void run();
	private:

		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();

			VulkanoWindow appWindow{ WIDTH, HEIGHT, "Vulkano" };
			VulkanoDevice vulkanoDevice{ appWindow };
			VulkanoSwapchain vulkanoSwapchain{ vulkanoDevice, appWindow.getExtent()};
			std::unique_ptr<VulkanoPipeline> vulkanoPipeline;
			VkPipelineLayout pipelineLayout;
			std::vector<VkCommandBuffer> commandBuffers;
	};

}

