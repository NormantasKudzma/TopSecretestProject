#include "Map.hpp"

Map::Map(unsigned int width, unsigned int height)
	: width(width)
	, height(height)
	, nodeCount(0)
{
	nodes = new Node[width * height];

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			nodes[y * width + x].SetX(x);
			nodes[y * width + x].SetY(y);
		}
	}
}

Map::~Map()
{
	if (nodes != nullptr)
	{
		delete[] nodes;
	}
}

bool Map::isValid(int x, int y)
{
	return (x >= 0 || x < width - 1 || y >= 0 || y < height - 1);
}

Node* Map::GetNode(int x, int y)
{
	Node* result = nullptr;

	if (isValid(x, y) == true)
	{
		result = &nodes[y * width + x];

		if (result->IsEnabled() == false)
		{
			result = nullptr;
		}
	}

	return result;
}

void Map::AddNode(int x, int y)
{
	nodes[y * width + x].SetEnabled(true);
	nodeCount += 1;
}

void Map::RemoveNode(int x, int y)
{
	nodes[y * width + x].SetEnabled(false);

	if (nodeCount > 0)
	{
		nodeCount -= 1;
	}
}

void Map::Optimize()
{
	for (int i = 0; i < width * height; i++)
	{
		if (nodes[i].IsEnabled() == true)
		{
			Node* neighbour = nullptr;
			Node* newNeighbour = nullptr;

			if ((neighbour = nodes[i].GetNeighbour(Node::Direction::Top)) != nullptr)
			{
				newNeighbour = neighbour;

				while (newNeighbour->GetNeighbour(Node::Direction::Top) != nullptr && newNeighbour->GetNeighbour(Node::Direction::Left) == nullptr && newNeighbour->GetNeighbour(Node::Direction::Right) == nullptr)
				{
					RemoveNode(newNeighbour->GetX(), newNeighbour->GetY());
					newNeighbour = newNeighbour->GetNeighbour(Node::Direction::Top);
				}

				nodes[i].SetNeighbour(newNeighbour, Node::Direction::Top);
			}

			if ((neighbour = nodes[i].GetNeighbour(Node::Direction::Left)) != nullptr)
			{
				newNeighbour = neighbour;

				while (newNeighbour->GetNeighbour(Node::Direction::Left) != nullptr && newNeighbour->GetNeighbour(Node::Direction::Top) == nullptr && newNeighbour->GetNeighbour(Node::Direction::Bottom) == nullptr)
				{
					RemoveNode(newNeighbour->GetX(), newNeighbour->GetY());
					newNeighbour = newNeighbour->GetNeighbour(Node::Direction::Left);
				}

				nodes[i].SetNeighbour(newNeighbour, Node::Direction::Left);
			}

			if ((neighbour = nodes[i].GetNeighbour(Node::Direction::Right)) != nullptr)
			{
				newNeighbour = neighbour;

				while (newNeighbour->GetNeighbour(Node::Direction::Right) != nullptr && newNeighbour->GetNeighbour(Node::Direction::Top) == nullptr && newNeighbour->GetNeighbour(Node::Direction::Bottom) == nullptr)
				{
					RemoveNode(newNeighbour->GetX(), newNeighbour->GetY());
					newNeighbour = newNeighbour->GetNeighbour(Node::Direction::Right);
				}

				nodes[i].SetNeighbour(newNeighbour, Node::Direction::Right);
			}

			if ((neighbour = nodes[i].GetNeighbour(Node::Direction::Bottom)) != nullptr)
			{
				newNeighbour = neighbour;

				while (newNeighbour->GetNeighbour(Node::Direction::Bottom) != nullptr && newNeighbour->GetNeighbour(Node::Direction::Left) == nullptr && newNeighbour->GetNeighbour(Node::Direction::Right) == nullptr)
				{
					RemoveNode(newNeighbour->GetX(), newNeighbour->GetY());
					newNeighbour = newNeighbour->GetNeighbour(Node::Direction::Bottom);
				}

				nodes[i].SetNeighbour(newNeighbour, Node::Direction::Bottom);
			}
		}
	}
}