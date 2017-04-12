#pragma once

class Node
{
public:
	Node(unsigned int x, unsigned int y);
	~Node();

	unsigned int x;
	unsigned int y;

	Node* leftNode;
	Node* rightNode;
	Node* topNode;
	Node* bottomNode;
};