#include "ImageBMP.hpp"

ImageBMP::ImageBMP(const char* filename)
	: bmpHeader(nullptr)
	, bmpInfo(nullptr)
	, fileBuffer(nullptr)
	, fileBufferSize(0)
	, pixelBuffer(nullptr)
	, pixelBufferSize(0)
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
	pixelBufferSize = bmpHeader->bfSize - bmpHeader->bfOffBits;

	width = bmpInfo->biWidth;
	height = bmpInfo->biHeight;
	channelCount = bmpInfo->biBitCount / 8;
}

ImageBMP::~ImageBMP()
{
	if (fileBuffer != nullptr)
		delete fileBuffer;
}

void ImageBMP::Save(const char* filename)
{
	FILE* file = nullptr;
	fopen_s(&file, filename, "wb");

	fwrite(fileBuffer, sizeof(char), fileBufferSize, file);

	fclose(file);
}