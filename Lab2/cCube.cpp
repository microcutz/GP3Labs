/*
==================================================================================
cCube.cpp
==================================================================================
*/

#include "cCube.h"

PFNGLGENBUFFERSARBPROC glGenBuffers = NULL;
PFNGLBINDBUFFERPROC glBindBuffer = NULL;
PFNGLBUFFERDATAPROC glBufferData = NULL;

cCube::cCube()
{
	m_rotAngle = 0.0f;
}

void cCube::renderCube(float rotAngle)
{
	//glRotatef(rotAngle, 0.0f, 1.0f, 0.0f);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

float cCube::getRotAngle()
{
	return m_rotAngle;
}

void cCube::setRotAngle(float rotAngle)
{
	m_rotAngle = rotAngle;
}

void cCube::prepareCube(float rAngle)
{
	m_rotAngle = rAngle;
	if (m_rotAngle > 360.0f)
	{
		m_rotAngle -= 360.0f;
	}
}

void cCube::loadTextureCoords() // Lab 3
{
	m_CubeTextureIndices[0] = glm::vec2(0.5f, 0.66f);
	m_CubeTextureIndices[1] = glm::vec2(0.5f, 1.0f);
	m_CubeTextureIndices[2] = glm::vec2(1.0f, 0.66f);
	m_CubeTextureIndices[3] = glm::vec2(1.0f, 1.0f);

	m_CubeTextureIndices[4] = glm::vec2(0.5f, 0.0f);
	m_CubeTextureIndices[5] = glm::vec2(0.0f, 0.0f);
	m_CubeTextureIndices[6] = glm::vec2(0.5f, 0.33f);
	m_CubeTextureIndices[7] = glm::vec2(0.0f, 0.33f);

	m_CubeTextureIndices[8] = glm::vec2(0.0f, 0.66f);
	m_CubeTextureIndices[9] = glm::vec2(0.5f, 0.33f);
	m_CubeTextureIndices[10] = glm::vec2(0.0f, 0.33f);
	m_CubeTextureIndices[11] = glm::vec2(0.5f, 0.66f);

	m_CubeTextureIndices[12] = glm::vec2(0.5f, 0.33f);
	m_CubeTextureIndices[13] = glm::vec2(0.5f, 0.66f);
	m_CubeTextureIndices[14] = glm::vec2(1.0f, 0.66f);
	m_CubeTextureIndices[15] = glm::vec2(1.0f, 0.33f);

	m_CubeTextureIndices[16] = glm::vec2(0.0f, 0.66f);
	m_CubeTextureIndices[17] = glm::vec2(0.5f, 1.0f);
	m_CubeTextureIndices[18] = glm::vec2(0.5f, 0.66f);
	m_CubeTextureIndices[19] = glm::vec2(0.0f, 1.0f);

	m_CubeTextureIndices[20] = glm::vec2(0.5f, 0.0f);
	m_CubeTextureIndices[21] = glm::vec2(0.5f, 0.33f);
	m_CubeTextureIndices[22] = glm::vec2(1.0f, 0.33f);
	m_CubeTextureIndices[23] = glm::vec2(1.0f, 0.0f);
}

void cCube::initialiseCube(cImageLoader texture)
{	

	m_topLeftFront = glm::vec3(-1.0f, 1.0f, 1.0f);
	m_bottomLeftFront = glm::vec3(-1.0f, -1.0f, 1.0f);
	m_topRightFront = glm::vec3(1.0f, 1.0f, 1.0f);
	m_bottomRightFront = glm::vec3(1.0f, -1.0f, 1.0f);
	m_topLeftBack = glm::vec3(-1.0f, 1.0f, -1.0f);
	m_topRightBack = glm::vec3(1.0f, 1.0f, -1.0f);
	m_bottomLeftBack = glm::vec3(-1.0f, -1.0f, -1.0f);
	m_bottomRightBack = glm::vec3(1.0f, -1.0f, -1.0f);

	// Push back 8 vertices that make up a cube
	m_vertices.push_back(m_bottomLeftFront);
	m_vertices.push_back(m_bottomLeftBack);
	m_vertices.push_back(m_bottomRightBack);
	m_vertices.push_back(m_bottomRightFront);
	m_vertices.push_back(m_topLeftFront);
	m_vertices.push_back(m_topLeftBack);
	m_vertices.push_back(m_topRightBack);
	m_vertices.push_back(m_topRightFront);

	m_cubeIndices[0] = 0; // red front face
	m_cubeIndices[1] = 2;
	m_cubeIndices[2] = 3;
	m_cubeIndices[3] = 0;
	m_cubeIndices[4] = 1;
	m_cubeIndices[5] = 2;
	
	m_cubeIndices[6] = 4; // orange back face
	m_cubeIndices[7] = 6;
	m_cubeIndices[8] = 7;
	m_cubeIndices[9] = 4;
	m_cubeIndices[10] = 5;
	m_cubeIndices[11] = 6;
	
	m_cubeIndices[12] = 0; // yellow top face
	m_cubeIndices[13] = 4;
	m_cubeIndices[14] = 1;
	m_cubeIndices[15] = 4;
	m_cubeIndices[16] = 5;
	m_cubeIndices[17] = 1;
	
	m_cubeIndices[18] = 2; // purple bottom face
	m_cubeIndices[19] = 6;
	m_cubeIndices[20] = 3;
	m_cubeIndices[21] = 6;
	m_cubeIndices[22] = 7;
	m_cubeIndices[23] = 3;
	
	m_cubeIndices[24] = 6; // blue left face
	m_cubeIndices[25] = 1;
	m_cubeIndices[26] = 5;
	m_cubeIndices[27] = 6;
	m_cubeIndices[28] = 2;
	m_cubeIndices[29] = 1;
	
	m_cubeIndices[30] = 0; // green right face
	m_cubeIndices[31] = 7;
	m_cubeIndices[32] = 4;
	m_cubeIndices[33] = 0;
	m_cubeIndices[34] = 3;
	m_cubeIndices[35] = 7;
	
	// Call loadTextureCoords() - Lab 3
	loadTextureCoords();

	// Create Colour list
	cColours theColour;

	for (int Colour = 0; Colour < 7; Colour++)
	{
		m_colourList.push_back(theColour.getColour(static_cast<cColours::colours>(Colour)));
	}

	// Assign variables that will be used to store the unique objects ID's that will be used
	// to reger to the two buffers.
	glGenBuffers = (PFNGLGENBUFFERSARBPROC)wglGetProcAddress("glGenBuffers");
	glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
	
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	glGenBuffers(2, &m_VertexBufferObjects[0]);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[0]); //Bind the vertex buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* 3 *
	m_vertices.size(), &m_vertices[0], GL_STATIC_DRAW); //Send the data to OpenGL
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,
	m_VertexBufferObjects[1]); //Bind the vertex buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)* 36,
		&m_cubeIndices[0], GL_STATIC_DRAW); //Send the data to OpenGL
	
	// Lab3
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[3]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* 2 * 24, &m_CubeTextureIndices[0], GL_STATIC_DRAW);


	glGenBuffers(1, &m_TextureID);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);

	// Store the texture data for OpenGL use - Lab 3
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_BGRA, texture.getImageWidth(), texture.getImageHeight(), GL_BGRA, 0, GL_UNSIGNED_BYTE, texture.getImageData());

	// Lab 3
	// Bind the colour array, and set the colour pointer to point at it
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[3]);
	glTexCoordPointer(2, GL_FLOAT, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[3]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* 3 *
		m_colourList.size(), &m_colourList[0], GL_STATIC_DRAW); //Send the data to OpenGL
	
	//Bind the colour array, and set the color pointer to point at it
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[3]);
	glColorPointer(3, GL_FLOAT, 0, 0);
	
	//Bind the vertex array and set the vertex pointer to point at it
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[0]);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	
	glTranslatef(0.0f, 0.0f, -6.0f);
	glRotatef(30.0f, 0.0f, 1.0f, 0.0f);

	
}

