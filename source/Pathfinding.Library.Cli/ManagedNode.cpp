#include "pch.h"
#include "ManagedNode.h"
#include "ManagedGraph.h"
#include "ManagedPoint.h"

using namespace System;
using namespace std;
using namespace Library;

namespace Library
{
	namespace Cli
	{
		ManagedNode::ManagedNode(ManagedGraph^ graph, ManagedPoint^ location) :
			ManagedNode(graph, location->X, location->Y)
		{			
		}

		ManagedNode::ManagedNode(ManagedGraph^ graph, int x, int y) :
			ManagedNode(graph->UnmanagedGraph->At(x, y))
		{			
		}

		ManagedNode::ManagedNode(std::shared_ptr<Library::Node> node) :
			mNode(new shared_ptr<Node>())
		{	
			*mNode = node;
		}

		ManagedNode::~ManagedNode()
		{
			delete mNode;
		}

		Guid^ ManagedNode::ID::get()
		{
			return *reinterpret_cast<Guid*>(const_cast<GUID *>(&(*mNode)->ID()));
		}

		ManagedNodeType ManagedNode::Type::get()
		{
			return (ManagedNodeType)(*mNode)->Type();
		}

		ManagedPoint^ ManagedNode::Location::get()
		{
			auto location = (*mNode)->Location();
			return gcnew ManagedPoint(location.X(), location.Y());
		}

		float ManagedNode::PathCost::get()
		{
			return (*mNode)->PathCost();
		}

		float ManagedNode::Heuristic::get()
		{
			return (*mNode)->Heuristic();
		}

		float ManagedNode::TotalCost::get()
		{
			return (*mNode)->TotalCost();
		}

		void ManagedNode::Reset()
		{
			(*mNode)->Reset();
		}		

		Node* ManagedNode::UnmanagedNode::get()
		{
			return mNode->get();
		}
	}
}