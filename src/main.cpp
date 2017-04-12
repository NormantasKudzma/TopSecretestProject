#include "Common.hpp"

void main()
{
	ImageBMP* image = new ImageBMP("Test.bmp");

	unsigned int imageWidth = image->GetWidth();
	unsigned int imageHeight = image->GetHeight();
	unsigned int imageChannels = image->GetChannels();
	char* imagePixels = image->GetPixels();

	std::vector<Node*> map;

	for (unsigned int y = 0; y < imageHeight + 1; y++)
	{
		for (unsigned int x = 0; x < imageWidth + 1; x++)
		{
			/*if (imagePixels[y * imageWidth + x] > 0)
			{
				Node* node = new Node(x, y);
				map.push_back(node);
			}*/
			
		}
	}

	image->Save("TestWrite.bmp");
}