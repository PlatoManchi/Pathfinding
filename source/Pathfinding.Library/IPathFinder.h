#pragma once

#include "Node.h"
#include <deque>
#include <set>
#include <memory>

namespace Library
{
	class Graph;

	class IPathFinder
	{
	public:
		virtual ~IPathFinder() { };
		virtual std::deque<std::shared_ptr<Node>> FindPath(std::shared_ptr<Node> start, std::shared_ptr<Node> end, std::set<std::shared_ptr<Node>>& closedSet) = 0;
		std::deque<std::shared_ptr<Node>> FindPath(std::shared_ptr<Node> start, std::shared_ptr<Node> end);
	};
}