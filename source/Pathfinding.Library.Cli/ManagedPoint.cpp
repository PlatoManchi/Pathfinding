#include "pch.h"
#include "ManagedPoint.h"

using namespace System;
using namespace Library;

namespace Library
{
	namespace Cli
	{
		ManagedPoint::ManagedPoint(int x, int y) :
			mPoint(new Point(x, y))
		{
		}

		ManagedPoint::ManagedPoint(const Point& point) :
			mPoint(new Point(point))
		{
		}

		ManagedPoint::~ManagedPoint()
		{
			delete mPoint;
		}

		bool ManagedPoint::operator==(ManagedPoint^ lhs, ManagedPoint^ rhs)
		{
			if (ReferenceEquals(lhs, rhs))
			{
				return true;
			}
			else if (ReferenceEquals(lhs, nullptr) || ReferenceEquals(rhs, nullptr))
			{
				return false;
			}

			return (lhs->X == rhs->X && lhs->Y == rhs->Y);
		}

		bool ManagedPoint::operator!=(ManagedPoint^ lhs, ManagedPoint^ rhs)
		{
			return !operator==(lhs, rhs);
		}

		bool ManagedPoint::Equals(Object^ other)
		{
			return (other->GetType() == ManagedPoint::typeid ? this == other : false);
		}

		int ManagedPoint::X::get()
		{
			return mPoint->X();
		}

		int ManagedPoint::Y::get()
		{
			return mPoint->Y();
		}
	}
}

