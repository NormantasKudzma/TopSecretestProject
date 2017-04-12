#pragma once

#include "Common.hpp"

class ImageBMP
{
public:

	ImageBMP(const char* filename);
	~ImageBMP();

	void Save(const char* filename);

	unsigned int GetWidth() { return width;	}
	unsigned int GetHeight() { return height; }
	unsigned int GetChannels() { return channelCount; }

	char* GetPixels() { return pixelBuffer; }

private:

	BITMAPFILEHEADER* bmpHeader;
	BITMAPINFOHEADER* bmpInfo;

	char* fileBuffer;
	unsigned int fileBufferSize;

	char* pixelBuffer;
	unsigned int pixelBufferSize;

	unsigned int width;
	unsigned int height;
	unsigned int channelCount;
};