#pragma once
#include <string>

#include <string>

// Enum to distinguish between a model loaded from a file or from raw points
enum class ModelFileType {
    File,
    Array
};

struct ModelData {

    static int modelsCount;
    static int generateNewId();

    // Public const fields — can be read but not modified after construction
    const ModelFileType type;
    const int id;
    const std::string modelPath;   // valid if type == FromFile
    const float* points;           // valid if type == FromPoints
    const int verticesNum;         // valid if type == FromPoints
    const bool isUv;
    // Constructor for a model loaded from a file
    ModelData(const std::string& modelPath)
        : type(ModelFileType::File), modelPath(modelPath),
          points(nullptr), verticesNum(0), isUv(true), id(generateNewId()){
    }

    // Constructor for a model defined by points
    ModelData(const float* points, int verticesNum, bool isUv = false)
        : type(ModelFileType::Array), modelPath(),
          points(points), verticesNum(verticesNum), isUv(isUv), id(generateNewId()) {}
};
