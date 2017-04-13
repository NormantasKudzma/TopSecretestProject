#pragma once

#include "Common.hpp"

class Node
{
public:

	enum Direction
	{
		Top = 0,
		Left,
		Right,
		Bottom,
		Count
	};

	Node();
	~Node();

	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }

	int GetX() { return x; }
	int GetY() { return y; }

	void SetEnabled(bool enabled) {	this->enabled = enabled; }
	bool IsEnabled() {	return enabled; }

	Node* GetNeighbour(Direction direction);
	unsigned int GetDistance(Node* node);

	void SetNeighbour(Node* neighbour, Direction direction);

private:

	int x;
	int y;

	bool enabled;
	Node* neighbours[Direction::Count];
};