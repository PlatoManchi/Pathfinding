#include "Graph.h"

namespace Library
{
	inline const std::map<Point, std::shared_ptr<Node>>& Library::Graph::Nodes() const
	{
		return mNodes;
	}	

	inline std::shared_ptr<Node> Graph::At(const Point& location) const
	{
		return mNodes.at(location);
	}

	inline std::shared_ptr<Node> Graph::At(const int x, const int y) const
	{
		return At(Point(x, y));
	}

	inline bool Graph::Contains(const Point& location) const
	{
		return mNodes.find(location) != mNodes.end();
	}

	inline bool Graph::Contains(const int x, const int y) const
	{
		return Contains(Point(x, y));
	}
}