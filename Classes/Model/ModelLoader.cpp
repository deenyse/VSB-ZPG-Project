#include "ModelLoader.h"
#include "../../External/tiny_obj_loader.h"

std::unordered_map<std::string, Model*> ModelLoader::modelCache;

Model* ModelLoader::LoadFromArray(const float* points, int verticesNum) {
    return new Model(points, verticesNum);
}

Model* ModelLoader::LoadFromFile(const std::string objPath) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, objPath.c_str())) {
        throw std::runtime_error(warn + err);
    }

    std::vector<float> vertices; // positions + normals + texcoords

    for (const auto& shape : shapes) {
        for (const auto& index : shape.mesh.indices) {
            // Position
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 0]);
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 1]);
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 2]);

            // Normal
            if (!attrib.normals.empty()) {
                vertices.push_back(attrib.normals[3 * index.normal_index + 0]);
                vertices.push_back(attrib.normals[3 * index.normal_index + 1]);
                vertices.push_back(attrib.normals[3 * index.normal_index + 2]);
            } else {
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
            }

            // Texture coordinates
            if (!attrib.texcoords.empty() && index.texcoord_index >= 0) {
                vertices.push_back(attrib.texcoords[2 * index.texcoord_index + 0]); // u
                vertices.push_back(attrib.texcoords[2 * index.texcoord_index + 1]); // v
            } else {
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
            }
        }
    }

    return new Model(vertices); // only the model with vertex buffer, no textures
}




Model*  ModelLoader::LoadModel(ModelData modelData) {
    if (auto it = modelCache.find(modelData.modelName); it != modelCache.end()) {
        return it->second;
    }

    Model* loadedModel = nullptr;

    if (modelData.type == ModelFileType::File)
        loadedModel = LoadFromFile(modelData.modelPath);

    if (modelData.type == ModelFileType::Array)
        loadedModel = LoadFromArray(modelData.points, modelData.verticesNum);


    modelCache[modelData.modelName] =loadedModel;
    return loadedModel;
}