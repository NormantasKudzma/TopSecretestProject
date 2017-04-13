#include "ImageBMP.hpp"

ImageBMP::ImageBMP(const char* filename)
	: bmpHeader(nullptr)
	, bmpInfo(nullptr)
	, fileBuffer(nullptr)
	, fileBufferSize(0)
	, pixelBuffer(nullptr)
{
	FILE* file = nullptr;
	fopen_s(&file, filename, "rb");

	fseek(file, 0, SEEK_END);
	fileBufferSize = ftell(file);
	fseek(file, 0, SEEK_SET);

	fileBuffer = new char[fileBufferSize];
	fread(fileBuffer, fileBufferSize, sizeof(char), file);

	fclose(file);

	bmpHeader = reinterpret_cast<BITMAPFILEHEADER*>(fileBuffer);
	bmpInfo = reinterpret_cast<BITMAPINFOHEADER*>(fileBuffer + sizeof(BITMAPFILEHEADER));

	pixelBuffer = fileBuffer + bmpHeader->bfOffBits;
	width = bmpInfo->biWidth;
	height = bmpInfo->biHeight;
}

ImageBMP::~ImageBMP()
{
	if (fileBuffer != nullptr)
		delete fileBuffer;
}

bool ImageBMP::isValid(int x, int y)
{
	return (x >= 0 || x < width - 1 || y >= 0 || y < height - 1);
}

ImageBMP::Pixel* ImageBMP::GetPixel(int x, int y)
{
	Pixel* result = nullptr;

	if (isValid(x, y) == true)
	{
		result = reinterpret_cast<Pixel*>(&pixelBuffer[(y * width + x) * sizeof(Pixel) + y]);
	}
	
	return result;
}

void ImageBMP::SetPixel(int x, int y, const ImageBMP::Pixel& pixel)
{
	if (isValid(x, y) == true)
	{
		memcpy(&pixelBuffer[(y * width + x) * sizeof(Pixel) + y], &pixel, sizeof(Pixel));
	}
}

void ImageBMP::Save(const char* filename)
{
	FILE* file = nullptr;
	fopen_s(&file, filename, "wb");

	fwrite(fileBuffer, sizeof(char), fileBufferSize, file);

	fclose(file);
}