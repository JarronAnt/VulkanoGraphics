#pragma once
#include <string>
#include <vector>
#include "vulkano_device.hpp"

namespace Vulkano {

	struct PipelineConfigInfo
	{
		VkViewport viewport;
		VkRect2D scissor;
		VkPipelineViewportStateCreateInfo viewportInfo;
		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;
		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		VkPipelineLayout pipelineLayout = nullptr;
		VkRenderPass renderPass = nullptr;
		uint32_t subpass = 0;
	};

	class VulkanoPipeline {
	public:
		VulkanoPipeline(VulkanoDevice &device, const std::string& vertPath, const std::string& fragPath, const PipelineConfigInfo &configInfo);
		~VulkanoPipeline();

		VulkanoPipeline(const VulkanoPipeline&) = delete;
		VulkanoPipeline& operator=(const VulkanoPipeline&) = delete;

		static PipelineConfigInfo generateDefaultConfig(uint32_t width, uint32_t height);

	private:
		static std::vector<char> readFile(const std::string& filePath);

		void createGraphicsPipeline(const std::string& vertPath, const std::string& fragPath, const PipelineConfigInfo& info);

		void createShaderModule(std::vector<char> &code, VkShaderModule *shaderModule);

		VulkanoDevice& vulkanoDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}