/*
==========================================================================
cCube.h
==========================================================================
*/

#ifndef _CUBE_H
#define _CUBE_H

#include "windowOGL.h"
#include "glm\glm.hpp"
#include "glx\glext.h"
#include "wglext.h"
#include <vector>
#include "cColours.h"
#include "cImageLoader.h"

class cCube : public windowOGL
{
public:
	cCube();
	void renderCube(float rotAngle);
	float getRotAngle();
	void setRotAngle(float rotAngle);
	void prepareCube(float rAngle);
	void initialiseCube(cImageLoader texture);
	void loadTextureCoords();  // Lab 3

private:
	float m_rotAngle;
	glm::vec3 m_topLeftFront;
	glm::vec3 m_bottomLeftFront;
	glm::vec3 m_topRightFront;
	glm::vec3 m_bottomRightFront;
	glm::vec3 m_topLeftBack;
	glm::vec3 m_topRightBack;
	glm::vec3 m_bottomLeftBack;
	glm::vec3 m_bottomRightBack;

	glm::vec2 m_CubeTextureIndices[24];
	GLuint m_cubeIndices[36];

	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec3> m_colourList;
	GLuint m_VertexBufferObjects[4];

	GLuint m_TextureID;
};

#endif