#include "pch.h"
#include "GreedyBestFirst.h"

using namespace std;

namespace Library
{
	deque<shared_ptr<Node>> GreedyBestFirst::FindPath(shared_ptr<Node> start, shared_ptr<Node> end, set<shared_ptr<Node>>& closedSet)
	{
		// init
		shared_ptr<Node> currentNode = start;
		closedSet.insert(currentNode);
		set<shared_ptr<Node>> openSet;
		Point endLocation = end->Location();

		// loop through nodes until end is found or there are no nodes to loop 
		do
		{
			vector<weak_ptr<Node>> neighbours = currentNode->Neighbors();

			// loop through all neighbours
			for (weak_ptr<Node> node : neighbours)
			{
				shared_ptr<Node> shrdNode = node.lock();
				// if not present in closedSet
				if (closedSet.find(shrdNode) == closedSet.end())
				{
					shrdNode->SetParent(currentNode);
					// if not present in openSet
					if (openSet.find(shrdNode) == openSet.end())
					{
						// calculate heuristic
						Point nodeLocation = shrdNode->Location();
						float heuristic = (float)((endLocation.X() - nodeLocation.X()) + (endLocation.Y() - nodeLocation.Y()));
						shrdNode->SetHeuristic(heuristic);

						// insert into openSet
						openSet.insert(shrdNode);
					}
				}
			}

			// if open set is empty then there are no nodes to search for
			if (openSet.size() == 0)
			{
				break;
			}

			currentNode = NodeWithLeastHeuristic(openSet);
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

		return path;
	}

	std::shared_ptr<Node> GreedyBestFirst::NodeWithLeastHeuristic(std::set<std::shared_ptr<Node>>& openSet) const
	{
		shared_ptr<Node> result = *openSet.begin();

		for (shared_ptr<Node> node : openSet)
		{
			if (result->Heuristic() > node->Heuristic())
			{
				result = node;
			}
		}

		return result;
	}
}