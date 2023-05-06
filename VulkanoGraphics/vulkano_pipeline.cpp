#include "vulkano_pipeline.hpp"
#include <iostream>
#include <fstream>

namespace Vulkano {

	VulkanoPipeline::VulkanoPipeline(VulkanoDevice& device, const std::string& vertPath, const std::string& fragPath, const PipelineConfigInfo& info) :vulkanoDevice{device}
	{
		createGraphicsPipeline(vertPath, fragPath, info);
	}

	PipelineConfigInfo VulkanoPipeline::generateDefaultConfig(uint32_t width, uint32_t height)
	{
		PipelineConfigInfo info{};
		return info;
	}

	std::vector<char> VulkanoPipeline::readFile(const std::string& filePath) {
		std::ifstream file(filePath, std::ios::ate | std::ios::binary);

		if (!file.is_open()) {
			throw std::runtime_error("failed to open file " + filePath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();

		return buffer;
	}

	void VulkanoPipeline::createGraphicsPipeline(const std::string& vertPath, const std::string& fragPath, const PipelineConfigInfo& info)
	{
		auto vertCode = readFile(vertPath);
		auto fragCode = readFile(fragPath);

		std::cout << vertCode.size() << std::endl;
		std::cout << fragCode.size() << std::endl;
	}

	void VulkanoPipeline::createShaderModule(std::vector<char>& code, VkShaderModule* shaderModule)
	{
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<uint32_t*>(code.data()); //vulkan expects uint32 pointer so have to recast

		if (vkCreateShaderModule(vulkanoDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
			throw std::runtime_error("failed to create shader module");
		}
	}

}