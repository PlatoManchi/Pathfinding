#include "pch.h"
#include "Graph.h"
#include "GridHelper.h"
#include "Node.h"
#include "BreadthFirstSearch.h"
#include "GreedyBestFirst.h"
#include "DijkstraAlgorithm.h"
#include "AStarAlgorithm.h"
#include "StopWatch.h"

using namespace Library;
using namespace std;
int main(int argc, char* argv[])
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	int32_t width, height;

	Graph graph = GridHelper::LoadGridFromFile("Grid.grid", width, height);

	cout << "Map data:"<< endl;
	for (int32_t y = 0; y < height; ++y)
	{
		for (int32_t x = 0; x < width; ++x)
		{
			shared_ptr<Node> node = graph.At(x, y);
			cout << (node->Type() == NodeType::Normal ? "-" : "|") << " ";
		}

		cout << endl;
	}

	int startX = -1, startY = -1;
	int endX = -1, endY = -1;
	string input;

	while (true)
	{
		cout << endl << "Start point: ";
		getline(cin, input);
		sscanf_s(input.c_str(), "%d,%d", &startX, &startY);
		string errorReason = "";
		if (graph.Contains(startX, startY))
		{
			if (graph.At(startX, startY)->Type() != NodeType::Wall)
			{
				break;
			}
			else
			{
				errorReason = "Wall cannot be end point";
			}
		}
		else
		{
			errorReason = "Out of map size";
		}
		cout << "Invalid input. (" << errorReason << ")" << endl;
	}
	
	while (true)
	{
		cout << endl << "End point: ";
		getline(cin, input);
		sscanf_s(input.c_str(), "%d,%d", &endX, &endY);
		string errorReason = "";
		if (graph.Contains(endX, endY))
		{
			if (graph.At(endX, endY)->Type() != NodeType::Wall)
			{
				break;
			}
			else
			{
				errorReason = "Wall cannot be end point";
			}
		}
		else
		{
			errorReason = "Out of map size";
		}
		cout << "Invalid input. (" << errorReason << ")" << endl;
	}

	// creating list of all pathfinding algorithms
	map<string, shared_ptr<IPathFinder>> pathfindingAlgorithms;
	pathfindingAlgorithms["Breath-First Search"] = make_shared<BreadthFirstSearch>();
	pathfindingAlgorithms["Greedy Best-First"] = make_shared<GreedyBestFirst>();
	pathfindingAlgorithms["Dijkstra Algorithm"] = make_shared<DijkstraAlgorithm>();
	pathfindingAlgorithms["AStar Algorithm"] = make_shared<AStarAlgorithm>();

	StopWatch stopWatch;
	for (pair<string, shared_ptr<IPathFinder>> pair : pathfindingAlgorithms)
	{
		graph.Reset();
		stopWatch.Reset();

		cout << endl << "----------------------------------";
		cout << endl << "\t" << pair.first;
		cout << endl << "----------------------------------" << endl;

		shared_ptr<Node> start = graph.At(startX, startY);
		shared_ptr<Node> end = graph.At(endX, endY);

		set<shared_ptr<Node>> closedSet;

		stopWatch.Start();
		deque<shared_ptr<Node>> path = pair.second->FindPath(start, end, closedSet);
		stopWatch.Stop();
		for (int32_t y = 0; y < height; ++y)
		{
			for (int32_t x = 0; x < width; ++x)
			{
				shared_ptr<Node> node = graph.At(x, y);
				string str = (node->Type() == NodeType::Normal ? "-" : "|");
				if (node == start)
				{
					str = "S";
				}
				else if (node == end)
				{
					str = "E";
				}
				else if (find(path.begin(), path.end(), node) != path.end())
				{
					str = "x";
				}
				cout << str << " ";
			}

			cout << endl;
		}

		cout << endl << "Total nodes visited: " << closedSet.size();
		cout << endl << "Time took to calculate path: " << stopWatch.ElapsedMilliseconds().count() << " ms" << endl;
	}

	return 0;
}