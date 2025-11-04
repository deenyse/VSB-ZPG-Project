#include "DrawableObject.h"



DrawableObject::DrawableObject(const float* points, int verticiesNum, Camera* camera, ShaderPair shaderSource, LightManager* lighMmanager) : verticesNum(verticiesNum){
	shaderProgram = new ShaderProgram(new Shader(GL_VERTEX_SHADER, shaderSource.vertex), new Shader(GL_FRAGMENT_SHADER, shaderSource.fragment), camera, lighMmanager);
	model = new Model(points, verticiesNum); // create the model (VAO,VBO)
	transformations = new Transform();
};

DrawableObject::DrawableObject(const std::string& objPath, Camera* camera, ShaderPair shaderSource, LightManager* lightManager) {
    // Initialize shader program
    shaderProgram = new ShaderProgram(
        new Shader(GL_VERTEX_SHADER, shaderSource.vertex),
        new Shader(GL_FRAGMENT_SHADER, shaderSource.fragment),
        camera, lightManager
    );

    // TinyOBJLoader structures
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    // Load OBJ
    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, objPath.c_str())) {
        throw std::runtime_error(warn + err);
    }

    std::vector<float> vertices;

    // Convert OBJ data to float array: positions + normals
    for (const auto& shape : shapes) {
        for (const auto& index : shape.mesh.indices) {
            // Position
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 0]);
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 1]);
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 2]);

            // Normal (use 0,0,0 if not present)
            if (!attrib.normals.empty()) {
                vertices.push_back(attrib.normals[3 * index.normal_index + 0]);
                vertices.push_back(attrib.normals[3 * index.normal_index + 1]);
                vertices.push_back(attrib.normals[3 * index.normal_index + 2]);
            }
            else {
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
            }
        }
    }

    // Create model using vector constructor
    model = new Model(vertices);
    verticesNum = vertices.size() / 6;

    transformations = new Transform();
}

void DrawableObject::draw()
{
	notify(ObservableSubjects::SObject);
	shaderProgram->useProgram(); // use the shader program of this object
	shaderProgram->setUniform("modelMatrix", transformations->getMatrix()); //set the model matrix uniform in the shader

	model->bind(); //bind the VAO of the model

	glDrawArrays(GL_TRIANGLES, 0, verticesNum); //mode,first,count

	glBindVertexArray(0);
	glUseProgram(0);

}

Transform* DrawableObject::getTransformations() {
	return transformations;
}