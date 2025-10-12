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
//3. Add ability to chain transformations on DrawableObject
//		// Maby do it with operator overloading? by vector?
// 
// Is there sence in making Scene manager like i have with Transorm?
//


int main(void)
{

	
	auto app = new App();

	app->init();

	app->run();

}