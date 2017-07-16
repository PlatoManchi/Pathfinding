#include "pch.h"
#include "ManagedGraph.h"
#include "ManagedPoint.h"
#include "ManagedNode.h"

using namespace Library;

namespace Library
{
	namespace Cli
	{
		ManagedGraph::ManagedGraph(Graph& graph) :
			mGraph(new Graph(graph))
		{
		}

		ManagedGraph::~ManagedGraph()
		{
			delete mGraph;
		}

		ManagedNode^ ManagedGraph::default::get(ManagedPoint^ location)
		{
			return gcnew ManagedNode(this, location);
		}

		ManagedNode^ ManagedGraph::default::get(int x, int y)
		{
			return gcnew ManagedNode(this, x, y);
		}

		bool ManagedGraph::Contains(ManagedPoint^ location)
		{
			return mGraph->Contains(location->X, location->Y);
		}

		bool ManagedGraph::Contains(int x, int y)
		{
			return mGraph->Contains(x, y);
		}

		Graph* ManagedGraph::UnmanagedGraph::get()
		{
			return mGraph;
		}
	}
}