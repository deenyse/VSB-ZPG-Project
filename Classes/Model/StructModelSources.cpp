#include "StructModelSources.h"

//Models
#include "../../Models/bushes.h" // 8730 || bushes

#include "../../Models/tree.h"// 92814 || tree
#include "../../Models/plain.h"// 6 || house
#include "../../Models/sphere.h"// 2880 || sphere
#include "../../Models/suzi_smooth.h"// 2904 || sphere


// Model from file
const ModelData ModelSources::Formula1("Models/formula1.obj");
const ModelData ModelSources::Toiled( "Models/toiled.obj");
const ModelData ModelSources::Shrek( "Models/shrek.obj");
const ModelData ModelSources::Fiona( "Models/fiona.obj");
const ModelData ModelSources::Sky( "Models/skydome.obj");
const ModelData ModelSources::SteamMachine( "Models/SteamMachine.obj");
const ModelData ModelSources::XboxFridge( "Models/xbox-fridge.obj");
const ModelData ModelSources::Planet( "Models/planet.obj");
// Models from points
const ModelData ModelSources::Sphere( sphere, 2880);
const ModelData ModelSources::Tree( tree, 92814);
const ModelData ModelSources::Plain(plain, 6, true);
const ModelData ModelSources::Suzi( suziSmooth, 2904);
const ModelData ModelSources::Bushes(bushes, 8730);