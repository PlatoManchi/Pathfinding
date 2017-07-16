#include "pch.h"
#include "Node.h"

namespace Library
{
	Node::Node(const Point& location, NodeType type) :
		mLocation(location), mType(type), mHeuristic(0.0f), mPathCost(0.0f), mTotalCost(0.0f)
	{
		CoCreateGuid(&mID);
	}
}