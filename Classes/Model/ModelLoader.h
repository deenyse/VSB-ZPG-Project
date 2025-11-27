#pragma once

#include "ModelData.h"
#include "Models.h"

#include <string>
#include <unordered_map>

#include "ModelInstance.h"
class ModelLoader {
private:
    static std::unordered_map<int, ModelInstance*> modelCache;

    static ModelInstance* LoadFromFile(const std::string objPath);
    static ModelInstance* LoadFromArray(const float* points, int verticesNum, bool isUv);
public:
    static ModelInstance* LoadModel(const ModelDataBase* modelData);

};