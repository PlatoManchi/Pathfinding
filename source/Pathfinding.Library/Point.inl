#include "Point.h"
namespace Library
{
	inline bool Point::operator<(const Point& rhs) const
	{
		return (mX == rhs.mX ? mY < rhs.mY : mX < rhs.mX);
	}

	inline std::int32_t Point::X() const
	{
		return mX;
	}

	inline std::int32_t Point::Y() const
	{
		return mY;
	}
}