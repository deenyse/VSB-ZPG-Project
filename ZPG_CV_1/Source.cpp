#include "Application.h"

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 100.0f);

// Camera matrix
glm::mat4 View = glm::lookAt(
	glm::vec3(10, 10, 10), // Camera is at (4,3,-3), in World Space
	glm::vec3(0, 0, 0), // and looks at the origin
	glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
);

// Model matrix : an identity matrix (model will be at the origin)
glm::mat4 Model = glm::mat4(1.0f);


/*
TODO:
0. Fix uncompiling shader issue | at create shaders having shaderProgram and VAO as local variables
1. Fix 	std::vector<Model*> models; -- surving not a type issue
2. Remoove global VAO definition at App //GLuint VAO = 0;//TEST
3. Find another place for CallBack definitions | probably moove into separate Function
4. Implement Model class
5. Implement Triangle class
6. Add multiple models rendering
*/

int main(void)
{

	
	auto app = new App();

	app->init();


	app->createShaders();

	app->createModels();


	app->run();

}