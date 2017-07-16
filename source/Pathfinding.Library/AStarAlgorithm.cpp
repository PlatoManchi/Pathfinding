#include "pch.h"
#include "AStarAlgorithm.h"

using namespace std;
namespace Library
{
	deque<shared_ptr<Node>> AStarAlgorithm::FindPath(shared_ptr<Node> start, shared_ptr<Node> end, set<shared_ptr<Node>>& closedSet)
	{
		shared_ptr<Node> currentNode = start;
		closedSet.insert(currentNode);
		set<shared_ptr<Node>> openSet;
		Point endLocation = end->Location();

		do{
			vector<weak_ptr<Node>> neighbours = currentNode->Neighbors();
			for (weak_ptr<Node> node : neighbours)
			{
				shared_ptr<Node> shrdNode = node.lock();
				if (closedSet.find(shrdNode) == closedSet.end())
				{
					// pathcost is parent path cost + const cost to cross the node (1)
					float pathCost = currentNode->PathCost() + 1.0f;

					// if openSet has the node
					if (openSet.find(shrdNode) != openSet.end())
					{
						// if current path cost is less than node's pathcost then update node
						if (pathCost < shrdNode->PathCost())
						{
							shrdNode->SetParent(currentNode);
							shrdNode->SetPathCost(pathCost);
						}
					}
					else
					{
						// calculate heuristic
						Point nodeLocation = shrdNode->Location();
						float heuristic = (float)((endLocation.X() - nodeLocation.X()) + (endLocation.Y() - nodeLocation.Y()));
						shrdNode->SetHeuristic(heuristic);

						shrdNode->SetParent(currentNode);
						shrdNode->SetPathCost(pathCost);
						openSet.insert(shrdNode);
					}
				}
			}

			// early out
			if (openSet.size() == 0)
			{
				break;
			}

			currentNode = NodeWithLeastTotalCost(openSet);
			openSet.erase(currentNode);
			closedSet.insert(currentNode);
		} while (currentNode != end);

		// path : to be built when the parsing is done.
		deque<shared_ptr<Node>> path;
		currentNode = end;
		while (!currentNode->Parent().expired())
		{
			shared_ptr<Node> parent = currentNode->Parent().lock();
			path.push_back(parent);
			currentNode = parent;
		}

		return path;;
	}

	shared_ptr<Node> AStarAlgorithm::NodeWithLeastTotalCost(set<shared_ptr<Node>>& openSet) const
	{
		shared_ptr<Node> result = *openSet.begin();

		for (shared_ptr<Node> node : openSet)
		{
			if (result->TotalCost() > node->TotalCost())
			{
				result = node;
			}
		}

		return result;
	}
}