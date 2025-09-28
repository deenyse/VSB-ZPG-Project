#pragma once
//Include GLEW
#include <GL/glew.h>
class Model
{
protected:
	GLuint VBO, VAO;
public:
	//Model();
	virtual void create()=0;
	virtual void draw()=0;
};
