#pragma once

#include "StructModelData.h"
#include "StructModelSources.h"

#include <string>
#include <unordered_map>

#include "Model.h"
class ModelLoader {
private:
    static std::unordered_map<std::string, Model*> modelCache;

    static Model* LoadFromFile(const std::string objPath);
    static Model* LoadFromArray(const float* points, int verticesNum);
public:
    static Model* LoadModel(ModelData modelData);

};