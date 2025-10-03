#pragma once


#include <glm/mat4x4.hpp> // glm::mat4

#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale

#include "IBasicTransform.h"
class Scale : public IBasicTransform
{
private:
public:
	Scale(int scaleFactor);
	void updateMatrix(glm::mat4& matrix) override;
};

