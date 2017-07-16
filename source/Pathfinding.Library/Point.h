#pragma once

#include <cstdint>

namespace Library
{
	class Point final
	{
	public:
		explicit Point(const std::int32_t x = 0, const std::int32_t y = 0);

		bool operator<(const Point& rhs) const;

		std::int32_t X() const;
		std::int32_t Y() const;		

	private:
		std::int32_t mX;
		std::int32_t mY;
	};
}

#include "Point.inl"