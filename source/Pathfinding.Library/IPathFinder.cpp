#include "pch.h"
#include "IPathFinder.h"

using namespace std;

namespace Library
{
	deque<shared_ptr<Node>> IPathFinder::FindPath(shared_ptr<Node> start, shared_ptr<Node> end)
	{
		set<shared_ptr<Node>> closedSet;
		return FindPath(start, end, closedSet);
	}
}