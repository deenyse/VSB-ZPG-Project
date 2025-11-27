#include "StructModelSources.h"

//Models
#include "../../Models/bushes.h" // 8730 || bushes

#include "../../Models/tree.h"// 92814 || tree
#include "../../Models/plain.h"// 6 || house
#include "../../Models/sphere.h"// 2880 || sphere
#include "../../Models/suzi_smooth.h"// 2904 || sphere


// Model from file
const ModelDataBase*  ModelSources::Toiled = new FileModel( "Models/toiled.obj");
const ModelDataBase*  ModelSources::Shrek= new FileModel( "Models/shrek.obj");
const ModelDataBase*  ModelSources::Fiona= new FileModel( "Models/fiona.obj");
const ModelDataBase*  ModelSources::Sky= new FileModel( "Models/skydome.obj");
const ModelDataBase*  ModelSources::SteamMachine= new FileModel( "Models/SteamMachine.obj");
const ModelDataBase*  ModelSources::Planet= new FileModel( "Models/planet.obj");
// Models from points
const ModelDataBase* ModelSources::Sphere= new ArrayModel( sphere, 2880);
const ModelDataBase* ModelSources::Tree= new ArrayModel( tree, 92814);
const ModelDataBase* ModelSources::Plain= new ArrayModel(plain, 6, true);
const ModelDataBase* ModelSources::Suzi= new ArrayModel( suziSmooth, 2904);
const ModelDataBase* ModelSources::Bushes= new ArrayModel(bushes, 8730);