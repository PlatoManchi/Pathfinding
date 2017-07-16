#pragma once

#using <System.dll>

namespace Library
{
	class Point;

	namespace Cli
	{
		public ref class ManagedPoint sealed
		{
		public:
			ManagedPoint(int x, int y);
			~ManagedPoint();

			static bool operator==(ManagedPoint^ lhs, ManagedPoint^ rhs);
			static bool operator!=(ManagedPoint^ lhs, ManagedPoint^ rhs);

			property int X { int get(); }
			property int Y { int get(); }
			
			virtual bool Equals(System::Object^ other) override;			

		internal:
			ManagedPoint(const Point& point);

		private:
			Library::Point* mPoint;
		};
	}
}