#pragma once

#include "Common.hpp"

class ImageBMP
{
public:

	struct Pixel
	{
		unsigned char b;
		unsigned char g;
		unsigned char r;

		unsigned char GetValue()
		{
			return (b + g + r) / 3;
		}
	};

	ImageBMP(const char* filename);
	~ImageBMP();

	void Save(const char* filename);

	unsigned int GetWidth() { return width;	}
	unsigned int GetHeight() { return height; }

	Pixel* GetPixel(int x, int y);
	void SetPixel(int x, int y, const Pixel& pixel);

private:

	bool isValid(int x, int y);

	BITMAPFILEHEADER* bmpHeader;
	BITMAPINFOHEADER* bmpInfo;

	char* fileBuffer;
	unsigned int fileBufferSize;

	char* pixelBuffer;
	unsigned int width;
	unsigned int height;
};