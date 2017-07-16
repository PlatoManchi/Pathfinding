#pragma once

namespace Library
{
	class Graph;

	namespace Cli
	{
		ref class ManagedNode;
		ref class ManagedPoint;

		public ref class ManagedGraph sealed
		{
		public:
			~ManagedGraph();

			property ManagedNode^ default[ManagedPoint^]{ ManagedNode^ get(ManagedPoint^ location); }
			property ManagedNode^ default[int, int]{ ManagedNode^ get(int x, int y); }

			bool Contains(ManagedPoint^ location);
			bool Contains(int x, int y);

		internal:
			ManagedGraph(Graph& graph);

			property Library::Graph* UnmanagedGraph { Library::Graph* get(); }

		private:
			Library::Graph* mGraph;
		};
	}
}