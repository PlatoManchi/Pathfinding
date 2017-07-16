#include "pch.h"
#include "BreadthFirstSearch.h"

using namespace std;

namespace Library
{
	std::deque<std::shared_ptr<Node>> BreadthFirstSearch::FindPath(std::shared_ptr<Node> start, std::shared_ptr<Node> end, std::set<std::shared_ptr<Node>>& closedSet)
	{
		// clear the closed set.
		closedSet.clear();

		queue<weak_ptr<Node>> frontier;
		shared_ptr<Node> parentNode = start;
		closedSet.insert(parentNode);
		// populating initial frontier nodes
		vector<weak_ptr<Node>> neighbour = start->Neighbors();
		for (weak_ptr<Node> node : neighbour)
		{
			frontier.push(node);
			// setting parent while populating frontier
			shared_ptr<Node> shrdNode = node.lock();
			shrdNode->SetParent(parentNode);
		}

		// looping until all map is searched or end is found in frontier
		while (frontier.size() != 0)
		{
			shared_ptr<Node> currentSearchingNode = frontier.front().lock();
			frontier.pop();

			if (*currentSearchingNode == *end)
			{
				break;
			}

			// populating frontier with neighbours of current node
			vector<weak_ptr<Node>> neighbours = currentSearchingNode->Neighbors();
			for (weak_ptr<Node> node : neighbours)
			{
				shared_ptr<Node> shrdNode = node.lock();

				// check if the node is in closed set if not then process the node
				if (closedSet.find(shrdNode) == closedSet.end())
				{
					frontier.push(node);
					// setting parent while populating frontier
					shrdNode->SetParent(currentSearchingNode);
				}
				
			}

			// adding the currentNode to closed set since it is visited.
			closedSet.insert(currentSearchingNode);
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
}