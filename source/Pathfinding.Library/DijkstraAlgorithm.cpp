#include "pch.h"
#include "DijkstraAlgorithm.h"
using namespace std;

namespace Library
{
	deque<shared_ptr<Node>> DijkstraAlgorithm::FindPath(shared_ptr<Node> start, shared_ptr<Node> end, set<shared_ptr<Node>>& closedSet)
	{
		vector<shared_ptr<Node>> frontier;
		frontier.push_back(start);
		closedSet.insert(start);

		while (frontier.size() != 0)
		{
			shared_ptr<Node> currentNode = NodeWithLeastPathCost(frontier);
			// remove currentNode from frontier
			frontier.erase(find(frontier.begin(), frontier.end(), currentNode));
			
			// early exit
			if (currentNode == end)
			{
				break;
			}

			vector<weak_ptr<Node>> neighbours = currentNode->Neighbors();
			for (weak_ptr<Node> node : neighbours)
			{
				shared_ptr<Node> shrdNode = node.lock();

				// pathcost is parent path cost + const cost to cross the node (1)
				float pathCost = currentNode->PathCost() + 1.0f;
				float prevPathCost = shrdNode->PathCost();

				// if pathCost is less than previousPathCost, then update the node to new values
				if (prevPathCost > pathCost)
				{
					shrdNode->SetPathCost(pathCost);
					shrdNode->SetParent(currentNode);
					frontier.push_back(shrdNode);
				}

				// if the node is not there in closed set, set node's values and insert it into clsoed set.
				if (closedSet.find(shrdNode) == closedSet.end())
				{
					shrdNode->SetPathCost(pathCost);
					shrdNode->SetParent(currentNode);
					frontier.push_back(shrdNode);
					closedSet.insert(shrdNode);
				}
			}
		}

		// path : to be built when the parsing is done.
		deque<shared_ptr<Node>> path;
		shared_ptr<Node> currentNode = end;
		while (!currentNode->Parent().expired())
		{
			shared_ptr<Node> parent = currentNode->Parent().lock();
			path.push_back(parent);
			currentNode = parent;
		}

		return path;
	}

	shared_ptr<Node> DijkstraAlgorithm::NodeWithLeastPathCost(vector<shared_ptr<Node>>& openSet) const
	{
		shared_ptr<Node> result = openSet.front();

		for (shared_ptr<Node> node : openSet)
		{
			if (result->Heuristic() > node->PathCost())
			{
				result = node;
			}
		}

		return result;
	}
}