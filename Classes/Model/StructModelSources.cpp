#include "StructModelSources.h"

//Models
#include "../../Models/bushes.h" // 8730 || bushes

#include "../../Models/tree.h"// 92814 || tree
#include "../../Models/plain.h"// 6 || house
#include "../../Models/sphere.h"// 2880 || sphere


// Model from file
const ModelData ModelSources::Formula1("formula1", "Models/formula1.obj");
const ModelData ModelSources::Toiled("toiled", "Models/toiled.obj");
const ModelData ModelSources::Shrek("shrek", "Models/shrek.obj");
const ModelData ModelSources::Fiona("fiona", "Models/fiona.obj");
// Models from points
const ModelData ModelSources::Sphere("sphere", sphere, 2880);
const ModelData ModelSources::Tree("tree", tree, 92814);
const ModelData ModelSources::Plain("plain", plain, 6);
const ModelData ModelSources::Bushes("bushes", bushes, 8730);

