/*
=================
cImageLoader.h
=================
*/

#ifndef _IMAGELOADER_H
#define _IMAGELOADER_H

#include <Windows.h>
#include <GL/glut.h>
#include "FreeImage.h"

class cImageLoader
{
private:
	
	FIBITMAP *m_dib; // Pointer to the image, once loaded
	BYTE* m_ImageData; // Pointer to the data image
	unsigned int m_ImageWidth; // Image width
	unsigned int m_ImageHeight; // Image Height

public: 

	cImageLoader(); // Constructor
	cImageLoader(const char* filename); // Constructor
	~cImageLoader(); // Destructor

	FIBITMAP* LoadTexture(const char* filename); // Where to load the file from

	/*
	=================
	Getters & Setters
	=================
	*/
	BYTE* getImageData();
	void setImageData(FIBITMAP* texture);

	unsigned int getImageWidth();
	void setImageWidth(FIBITMAP* texture);

	unsigned int getImageHeight();
	void setImageHeight(FIBITMAP* texture);
	
	// Free the memory for a texture
	void unloadTexture(FIBITMAP* textureToUnload);
};
#endif