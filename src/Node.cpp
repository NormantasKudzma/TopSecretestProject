#include "Node.hpp"

Node::Node(unsigned int x, unsigned int y)
	: x(x)
	, y(y)
	, leftNode(nullptr)
	, rightNode(nullptr)
	, topNode(nullptr)
	, bottomNode(nullptr)
{

}

Node::~Node()
{
	leftNode = nullptr;
	rightNode = nullptr;
	topNode = nullptr;
	bottomNode = nullptr;
}