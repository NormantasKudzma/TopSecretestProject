#include "Node.hpp"

Node::Node()
	: enabled(false)
	, x(0)
	, y(0)
{

}

Node::~Node()
{

}

Node* Node::GetNeighbour(Direction direction)
{
	return neighbours[direction];
}

unsigned int Node::GetDistance(Node* node)
{
	return std::abs(x - node->GetX()) + std::abs(y - node->GetY());
}

void Node::SetNeighbour(Node* neighbour, Direction direction)
{
	neighbours[direction] = neighbour;
}