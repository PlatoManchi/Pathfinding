#include "pch.h"
#include "GridHelper.h"
#include "Utility.h"

using namespace std;

namespace Library
{
	Graph GridHelper::LoadGridFromFile(const string& filename)
	{
		int32_t gridWidth, gridHeight;

		return LoadGridFromFile(filename, gridWidth, gridHeight);
	}

	Graph GridHelper::LoadGridFromFile(const string& filename, int32_t& gridWidth, int32_t& gridHeight)
	{
		const Point NeighborOffsets[] = { Point(-1, 0), Point(1, 0), Point(0, -1), Point(0, 1) };

		ifstream inputFile(filename);
		if (inputFile.bad())
		{
			throw exception("Could not open file.");
		}

		// Read grid representation from file
		vector<vector<NodeType>> rawGrid;
		gridWidth = -1;
		while (inputFile.good())
		{
			string line;
			getline(inputFile, line);
			auto nodes = Utility::SplitString(line, ' ');
			if (gridWidth == -1)
			{
				gridWidth = static_cast<int32_t>(nodes.size());
			}
			else if (gridWidth != static_cast<int32_t>(nodes.size()))
			{
				throw new exception("Grid width must be uniform.");
			}

			vector<NodeType> row(gridWidth);
			for (int32_t i = 0; i < gridWidth; i++)
			{
				int nodeTypeValue = atoi(nodes[i].c_str());
				row[i] = static_cast<NodeType>(nodeTypeValue);
			}

			rawGrid.push_back(row);
		}

		inputFile.close();

		// Build grid from file representation
		gridHeight = static_cast<int32_t>(rawGrid.size());
		Graph graph;
		for (int y = 0; y < gridHeight; y++)
		{
			for (int x = 0; x < gridWidth; x++)
			{
				graph.AddNode(make_shared<Node>(Point(x, y), rawGrid[y][x]));
			}
		}

		// Assign adjacent nodes
		for (int y = 0; y < gridHeight; y++)
		{
			for (int x = 0; x < gridWidth; x++)
			{
				shared_ptr<Node> node = graph.At(x, y);

				for (const Point& offset : NeighborOffsets)
				{
					Point location(node->Location().X() + offset.X(), node->Location().Y() + offset.Y());
					if (IsValidGridLocation(location, gridWidth, gridHeight))
					{
						shared_ptr<Node> neighbor = graph.At(location);
						if (neighbor->Type() != NodeType::Wall)
						{
							node->Neighbors().push_back(neighbor);
						}
					}
				}
			}
		}

		return graph;
	}

	bool GridHelper::IsValidGridLocation(const Point& location, int maxWidth, int maxLength)
	{
		return (location.X() >= 0 && location.X() < maxWidth) && (location.Y() >= 0 && location.Y() < maxLength);
	}
}