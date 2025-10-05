#include "Application.h"

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

// TODO:
//1. Overload ShaderRenderer
//2. Create different test scenes
//3. Add into app class a claback handler
//4. Add ability to switch between scenes by keyboard input


//const float points[18] = {
//-0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // brm l
// 0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // btm r
// 0.0f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f  // top
//};

int main(void)
{

	
	auto app = new App();

	app->init();

	app->createScenes();

	app->run();

}