#pragma once

#include "Point.h"
#include "Node.h"
#include <map>

namespace Library
{
	class Graph final
	{
	public:
		const std::map<Point, std::shared_ptr<Node>>& Nodes() const;

		void AddNode(std::shared_ptr<Node> node);
		void Reset();
		std::shared_ptr<Node> At(const Point& location) const;
		std::shared_ptr<Node> At(const int x, const int y) const;
		bool Contains(const Point& location) const;
		bool Contains(const int x, const int y) const;

	private:
		std::map<Point, std::shared_ptr<Node>> mNodes;
	};
}

#include "Graph.inl"