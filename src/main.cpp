#include "Common.hpp"

void main()
{
	ImageBMP* image = new ImageBMP("Test.bmp");

	unsigned int imageHeight = image->GetHeight();
	unsigned int imageWidth = image->GetWidth();
	
	Map* map = new Map(imageWidth, imageHeight);

	for (unsigned int y = 0; y < imageHeight; y++)
	{
		for (unsigned int x = 0; x < imageWidth; x++)
		{
			if (image->GetPixel(x, y)->GetValue() > 0)
			{
				map->AddNode(x, y);
			}
		}
	}

	for (unsigned int y = 0; y < imageHeight; y++)
	{
		for (unsigned int x = 0; x < imageWidth; x++)
		{
			Node* node = map->GetNode(x, y);

			if (node != nullptr)
			{
				node->SetNeighbour(map->GetNode(x + 0, y + 1), Node::Direction::Top);
				node->SetNeighbour(map->GetNode(x - 1, y + 0), Node::Direction::Left);
				node->SetNeighbour(map->GetNode(x + 1, y + 0), Node::Direction::Right);
				node->SetNeighbour(map->GetNode(x + 0, y - 1), Node::Direction::Bottom);
			}
		}
	}

	map->Optimize();

	for (unsigned int y = 0; y < imageHeight; y++)
	{
		for (unsigned int x = 0; x < imageWidth; x++)
		{
			if (x % 3 == 0 && y % 3 == 0)
			{
				Node* node = map->GetNode(x, y);

				if (node != nullptr)
				{
					Node* neighbour = nullptr;

					if ((neighbour = node->GetNeighbour(Node::Direction::Top)) != nullptr)
						image->SetPixel(neighbour->GetX(), neighbour->GetY(), { 255,0,0 });

					if ((neighbour = node->GetNeighbour(Node::Direction::Left)) != nullptr)
						image->SetPixel(neighbour->GetX(), neighbour->GetY(), { 0,255,0 });

					if ((neighbour = node->GetNeighbour(Node::Direction::Right)) != nullptr)
						image->SetPixel(neighbour->GetX(), neighbour->GetY(), { 0,0,255 });

					if ((neighbour = node->GetNeighbour(Node::Direction::Bottom)) != nullptr)
						image->SetPixel(neighbour->GetX(), neighbour->GetY(), { 255,0,255 });
				}
			}
		}
	}

	image->Save("TestWrite.bmp");
}