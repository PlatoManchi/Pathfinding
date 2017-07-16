#include "pch.h"
#include "Graph.h"

using namespace std;

namespace Library
{
	void Graph::AddNode(shared_ptr<Node> node)
	{
		if (mNodes.find(node->Location()) != mNodes.end())
		{
			throw exception("Node with the same location already exists.");
		}

		mNodes.insert(make_pair(node->Location(), node));
	}

	void Graph::Reset()
	{
		for (auto& pair : mNodes)
		{
			pair.second->Reset();
		}
	}
}