#include "pch.h"
#include "ManagedGridHelper.h"
#include "ManagedGraph.h"

using namespace std;
using namespace System;
using namespace msclr::interop;
using namespace Library;

namespace Library
{
	namespace Cli
	{
		ManagedGraph^ ManagedGridHelper::LoadGridFromFile(String^ filename)
		{
			int graphWidth, graphHeight;
			return LoadGridFromFile(filename, graphWidth, graphHeight);
		}

		ManagedGraph^ ManagedGridHelper::LoadGridFromFile(String^ filename, [Out] int% graphWidth, [Out] int% graphHeight)
		{
			int32_t width, height;
			Graph graph = GridHelper::LoadGridFromFile(marshal_as<string>(filename), width, height);

			graphWidth = width;
			graphHeight = height;

			return gcnew ManagedGraph(graph);
		}
	}
}



