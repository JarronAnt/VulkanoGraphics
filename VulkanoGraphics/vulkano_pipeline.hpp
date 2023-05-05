#pragma once
#include <string>
#include <vector>

namespace Vulkano {
	class VulkanoPipeline {
	public:
		VulkanoPipeline(const std::string& vertPath, const std::string& fragPath);

	private:
		static std::vector<char> readFile(const std::string& filePath);

		void createGraphicsPipeline(const std::string& vertPath, const std::string& fragPath);
	};
}