#pragma once
//Include GLEW
#include <GL/glew.h>
class Model
{
protected:
	GLuint VBO, VAO;
public:
    Model() : VBO(0), VAO(0) {}
    virtual ~Model() {
        if (VBO) glDeleteBuffers(1, &VBO);
        if (VAO) glDeleteVertexArrays(1, &VAO);
    }
    virtual void create() {
		// Empty implementation, to be overridden in derived classes
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
    }
    virtual void draw() {
        glBindVertexArray(VAO);
		//Draw call (example, should be replaced with actual draw logic)
		glDrawArrays(GL_TRIANGLES, 0, 0);  // Replace 0 with actual vertex count
        glBindVertexArray(0);
    }
	// Pure virtual function to set geometry data
    virtual void setGeometry(const float* vertices, size_t size) = 0;
};
