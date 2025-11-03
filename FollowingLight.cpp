#include "FollowingLight.h"



FollowingLight::FollowingLight(const glm::vec3& col, float c, float l, float q) 
	: PointLight(glm::vec3(0.0f), col, c,l,q)
{
}

void FollowingLight::follow(DrawableObject* o) {
	target = o;
	o->attach(this);
}

void FollowingLight::update(ObservableSubjects subject) {
    if (subject == ObservableSubjects::SObject && target) {
        // Reset light position to zero at the beginning of the update
        position = glm::vec3(0.0f);

        // Get the transformation matrix of the target object
        glm::mat4 mat = target->getTransformations()->getMatrix();

        // Apply the matrix to the zero vector to get the world position of the target
        glm::vec4 result = mat * glm::vec4(position, 1.0f);

        position = glm::vec3(result);


        notify(ObservableSubjects::SLight);
    }

}
