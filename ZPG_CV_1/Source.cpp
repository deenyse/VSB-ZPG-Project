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


//M = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f));
//M = glm::rotate(M, angle, glm::vec3(1.0f, 0.0f, 0.0f));
//M = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, myView));
//M = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));

//TODO:
/*
1. Убрать коментарии не на ангийском языке
2. Разрисовать для себя УМЛ диаграмму системы и понять за что отвечает каждый модуль(Разобрать можно на примере раброты Боди)
3. Мне надо сделтаь отдельный класс для сцены, дабы легко можно было между ними переключаться


4. Сделать сцены для сдачи дз


*/

int main(void)
{


	
	auto app = new App();

	app->init();


	app->createShaders();

	app->createModels();


	app->run();

}