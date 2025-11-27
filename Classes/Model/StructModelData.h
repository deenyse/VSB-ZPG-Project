#pragma once
#include <string>

#include <string>

struct ModelData {

    static int modelsCount;
    static int generateNewId();

    // Public const fields — can be read but not modified after construction
    const int id;
    const std::string modelPath;   // valid if type == FromFile
    const float* points;           // valid if type == FromPoints
    const int verticesNum;         // valid if type == FromPoints
    const bool isUv;               // valid if type == FromPoints

    // Constructor for a model loaded from a file
    ModelData(const std::string& modelPath)
        : modelPath(modelPath), points(nullptr), verticesNum(0), isUv(true), id(generateNewId()){
    }

    // Constructor for a model defined by points
    ModelData(const float* points, int verticesNum, bool isUv = false) : modelPath(), points(points), verticesNum(verticesNum), isUv(isUv), id(generateNewId()) {}
};
