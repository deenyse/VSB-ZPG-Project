#include "ModelData.h"

int ModelDataBase::modelsCount = 0;

int ModelDataBase::generateNewId() {
    return modelsCount++;
}
