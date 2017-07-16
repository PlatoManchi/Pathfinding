#include "Node.h"
namespace Library
{	
	inline bool Node::operator<(const Node& rhs) const
	{
		size_t size = sizeof(mID.Data4);
		return (memcmp(mID.Data4, rhs.mID.Data4, size) < 0);
	}

	inline bool Node::operator==(const Node& rhs) const
	{
		return (mID == rhs.mID);
	}

	inline bool Node::operator!=(const Node& rhs) const
	{
		return !operator==(rhs);
	}

	inline const GUID & Node::ID() const
	{
		return mID;
	}

	inline NodeType Node::Type() const
	{
		return mType;
	}

	inline const Point& Node::Location() const
	{
		return mLocation;
	}

	inline float Node::PathCost() const
	{
		return mPathCost;
	}

	inline void Node::SetPathCost(float value)
	{
		if (mPathCost != value)
		{
			mPathCost = value;
			mTotalCost = mPathCost + mHeuristic;
		}
	}

	inline float Node::Heuristic() const
	{
		return mHeuristic;
	}

	inline void Node::SetHeuristic(float value)
	{
		if (mHeuristic != value)
		{
			mHeuristic = value;
			mTotalCost = mPathCost + mHeuristic;
		}
	}

	inline float Node::TotalCost() const
	{
		return mTotalCost;
	}

	inline std::vector<std::weak_ptr<Node>>& Node::Neighbors()
	{
		return mNeighbors;
	}

	inline const std::vector<std::weak_ptr<Node>>& Node::Neighbors() const
	{
		return mNeighbors;
	}

	inline std::weak_ptr<Node> Node::Parent() const
	{
		return mParent;
	}

	inline void Node::SetParent(std::shared_ptr<Node> parent)
	{
		mParent = parent;
	}

	inline void Node::Reset()
	{
		mHeuristic = 0.0f;
		mPathCost = 0.0f;
	}
}