#pragma once

#include "Point.h"
#include <vector>
#include <objbase.h>
#include <memory>

namespace Library
{
	enum class NodeType
	{
		Normal = 0,
		Wall = 1
	};

	class Node final
	{
	public:
		explicit Node(const Point& location, NodeType type = NodeType::Normal);
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
		Node(Node&&) = delete;
		Node& operator=(Node&&) = delete;
		~Node() = default;

		bool operator<(const Node& rhs) const;
		bool operator==(const Node& rhs) const;
		bool operator!=(const Node& rhs) const;

		const GUID& ID() const;
		NodeType Type() const;
		const Point& Location() const;
		
		float PathCost() const;
		void SetPathCost(float value);

		float Heuristic() const;
		void SetHeuristic(float value);

		float TotalCost() const;
		std::vector<std::weak_ptr<Node>>& Neighbors();
		const std::vector<std::weak_ptr<Node>>& Neighbors() const;
		
		std::weak_ptr<Node> Parent() const;
		void SetParent(std::shared_ptr<Node> parent);

		void Reset();

	private:
		GUID mID;
		NodeType mType;
		Point mLocation;
		float mHeuristic;
		float mPathCost;
		float mTotalCost;
		std::vector<std::weak_ptr<Node>> mNeighbors;
		std::weak_ptr<Node> mParent;
	};
}

#include "Node.inl"