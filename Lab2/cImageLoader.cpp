/*
================
cImageLoader.cpp
================
*/

#include "cImageLoader.h"

cImageLoader::cImageLoader()
{
	m_dib = NULL;
	m_ImageData = NULL;
	m_ImageWidth = 0;
	m_ImageHeight = 0;
}

cImageLoader::cImageLoader(const char* filename)
{
	m_dib = LoadTexture(filename);
}

cImageLoader::~cImageLoader() // Destructor
{
	// UnloadTexture (m_dib)
}

FIBITMAP* cImageLoader::LoadTexture(const char* filename)
{
	// Image format
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	// Pointer to the image, once loaded
	FIBITMAP *dib(0);
	// Pointer to the image data
	BYTE* bits(0);
	// Image width and height
	unsigned int width(0), height(0);

	// Check the file signature and deduct its format
	fif = FreeImage_GetFileType(filename, 0);
	// If still unknown, try to guess the file format from the file extension 
	if (fif == FIF_UNKNOWN)
	{
		fif == FreeImage_GetFIFFromFilename(filename);
	}
	// If still unknown, return falure
	if (fif = FIF_UNKNOWN)
	{
		return NULL;
	}
	setImageData(dib);
	setImageWidth(dib);
	setImageHeight(dib);

	bits = getImageData();
	width = getImageWidth();
	height = getImageHeight();

	// If this is somehow one of these failed (they shouldn't), return falure
	if ((bits == 0) || (width == 0) || (height == 0))
	{
		return NULL;
	}
	// Return success
	m_dib = dib;
	return dib;
}

BYTE* cImageLoader::getImageData()
{
	// Retrieve the image data
	return m_ImageData;
}

void cImageLoader::setImageData(FIBITMAP* texture)
{
	m_ImageData = FreeImage_GetBits(texture);
}

unsigned int cImageLoader::getImageWidth()
{
	// Get Image width
	return m_ImageWidth;
}

void cImageLoader::setImageWidth(FIBITMAP* texture)
{
	m_ImageWidth = FreeImage_GetWidth(texture);
}

unsigned int cImageLoader::getImageHeight()
{
	// Get image height
	return m_ImageHeight;
}

void cImageLoader::setImageHeight(FIBITMAP* texture)
{
	m_ImageHeight = FreeImage_GetHeight(texture);
}

// Free the memory for a texture
void cImageLoader::unloadTexture(FIBITMAP* textureToUnload)
{
	// Free FreeImage's copy of the data
	FreeImage_Unload(textureToUnload);
}