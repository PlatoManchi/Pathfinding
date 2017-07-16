#pragma once

#include <vector>
#include <string>

namespace Library
{
	class Utility final
	{
	public:
		static std::vector<std::string> SplitString(const std::string& input, char delimeter);
	};
}

