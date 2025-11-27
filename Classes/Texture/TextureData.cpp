#include "TextureData.h"

int TextureDataBase::texturesCount =0;

int TextureDataBase::generateNewId() {
    return texturesCount++;
}