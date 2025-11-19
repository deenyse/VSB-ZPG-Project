#include "StructMaterials.h"

const MaterialData* Materials::Wood    = new MaterialData(0.2f, 0.7f, 0.2f, 16.0f);
const MaterialData* Materials::Plastic = new MaterialData(0.1f, 0.5f, 0.3f, 32.0f);
const MaterialData* Materials::Metal   = new MaterialData(0.1f, 0.6f, 0.9f, 128.0f);
const MaterialData* Materials::Constant   = new MaterialData(1.f, 0.f, 0.f, 1.f);
const MaterialData* Materials::Skydome   = new MaterialData(0.3f, 0.f, 0.f, 1.f);
