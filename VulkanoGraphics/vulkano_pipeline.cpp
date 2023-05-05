#include "vulkano_pipeline.hpp"
#include <iostream>
#include <fstream>

namespace Vulkano {

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

	void VulkanoPipeline::createGraphicsPipeline(const std::string& vertPath, const std::string& fragPath)
	{
		auto vertCode = readFile(vertPath);
		auto fragCode = readFile(fragPath);

		std::cout << vertCode.size() << std::endl;
		std::cout << fragCode.size() << std::endl;
	}


	VulkanoPipeline::VulkanoPipeline(const std::string& vertPath, const std::string& fragPath)
	{
		createGraphicsPipeline(vertPath, fragPath);
	}
}