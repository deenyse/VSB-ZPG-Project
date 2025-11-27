#pragma once
#include <string>


struct ModelDataBase {
    static int modelsCount;
    static int generateNewId();
    const int id;
    ModelDataBase() : id(generateNewId()) {}
    virtual ~ModelDataBase() = default;
};

struct FileModel : public  ModelDataBase {
    const std::string modelPath;   // valid if type == FromFile
    FileModel(const std::string& modelPath) : ModelDataBase(), modelPath(modelPath) {}
};

struct ArrayModel : public ModelDataBase {
    const float* points;           // valid if type == FromPoints
    const int verticesNum;         // valid if type == FromPoints
    const bool isUv;               // valid if type == FromPoints
    ArrayModel(const float* points, int verticesNum, bool isUv = false) : ModelDataBase(), points(points), verticesNum(verticesNum), isUv(isUv) {}
};