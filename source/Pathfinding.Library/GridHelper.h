#pragma once

#include "Graph.h"
#include <string>
#include <cstdint>

namespace Library
{
	class GridHelper final
	{
	public:
		static Graph LoadGridFromFile(const std::string& filename);
		static Graph LoadGridFromFile(const std::string& filename, int32_t& graphWidth, int32_t& graphHeight);

	private:
		static bool IsValidGridLocation(const Point& location, int maxWidth, int maxLength);
	};
}