#pragma once

#include "Common.hpp"

class Node;

class Map
{
public:

	Map(unsigned int width, unsigned int height);
	~Map();

	Node* GetNode(int x, int y);
	void AddNode(int x, int y);
	void RemoveNode(int x, int y);

	void SetEntryNode(Node* node) {	entry = node; }
	Node* GetEntryNode() { return entry; }

	void SetExitNode(Node* node) { exit = node;	}
	Node* GetExitNode() { return exit; }

	unsigned int GetNodeCount() { return nodeCount; }

	void Optimize();

private:

	bool isValid(int x, int y);

	Node* entry;
	Node* exit;

	Node* nodes;
	unsigned int nodeCount;

	unsigned int width;
	unsigned int height;	
};