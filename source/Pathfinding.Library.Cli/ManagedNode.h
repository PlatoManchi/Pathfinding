#pragma once

#using <System.dll>
#include <memory>

namespace Library
{
	class Node;

	namespace Cli
	{
		ref class ManagedGraph;
		ref class ManagedPoint;

		public enum class ManagedNodeType
		{
			Normal = 0,
			Wall = 1
		};

		public ref class ManagedNode sealed
		{
		public:
			ManagedNode(ManagedGraph^ graph, ManagedPoint^ location);
			ManagedNode(ManagedGraph^ graph, int x, int y);
			~ManagedNode();

			property System::Guid^ ID { System::Guid^ get(); }
			property ManagedNodeType Type { ManagedNodeType get(); }
			property ManagedPoint^ Location { ManagedPoint^ get(); }
			property float PathCost { float get(); }
			property float Heuristic { float get(); }
			property float TotalCost { float get(); }

			void Reset();

		internal:
			ManagedNode(std::shared_ptr<Library::Node> node);

			property Library::Node* UnmanagedNode { Library::Node* get(); }

		private:
			std::shared_ptr<Library::Node>* mNode;			
		};
	}
}