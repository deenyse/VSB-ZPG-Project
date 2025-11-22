#include "StructModelData.h"

int ModelData::modelsCount = 0;

int ModelData::generateNewId() {
    return modelsCount++;
}
