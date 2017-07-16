#pragma once

#using <System.dll>

using namespace System::Runtime::InteropServices;

namespace Library
{
	class Graph;

	namespace Cli
	{
		ref class ManagedGraph;

		public ref class ManagedGridHelper sealed
		{
		public:
			static ManagedGraph^ LoadGridFromFile(System::String^ filename);
			static ManagedGraph^ LoadGridFromFile(System::String^ filename, [Out] int% graphWidth, [Out] int% graphHeight);
		};
	}
}