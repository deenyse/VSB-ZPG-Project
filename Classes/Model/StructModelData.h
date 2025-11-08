#pragma once
#include <string>

#include <string>

// Enum to distinguish between a model loaded from a file or from raw points
    enum class ModelFileType {
        File,
        Array
    };

struct ModelData {


    // Public const fields — can be read but not modified after construction
    const ModelFileType type;
    const std::string modelName;
    const std::string modelPath;   // valid if type == FromFile
    const float* points;           // valid if type == FromPoints
    const int verticesNum;         // valid if type == FromPoints

    // Constructor for a model loaded from a file
    ModelData(const std::string& modelName, const std::string& modelPath)
        : type(ModelFileType::File), modelName(modelName), modelPath(modelPath),
          points(nullptr), verticesNum(0) {}

    // Constructor for a model defined by points
    ModelData(const std::string& modelName, const float* points, int verticesNum)
        : type(ModelFileType::Array), modelName(modelName), modelPath(),
          points(points), verticesNum(verticesNum) {}
};
