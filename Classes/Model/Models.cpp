#include "Models.h"

//Models
#include "../../Models/bushes.h" // 8730 || bushes

#include "../../Models/tree.h"// 92814 || tree
#include "../../Models/plain.h"// 6 || house
#include "../../Models/sphere.h"// 2880 || sphere
#include "../../Models/suzi_smooth.h"// 2904 || sphere


// Model from file
const ModelDataBase*  Models::Toiled = new FileModel( "Models/toiled.obj");
const ModelDataBase*  Models::Shrek= new FileModel( "Models/shrek.obj");
const ModelDataBase*  Models::Fiona= new FileModel( "Models/fiona.obj");
const ModelDataBase*  Models::Sky= new FileModel( "Models/skydome.obj");
const ModelDataBase*  Models::SteamMachine= new FileModel( "Models/SteamMachine.obj");
const ModelDataBase*  Models::Planet= new FileModel( "Models/planet.obj");
const ModelDataBase*  Models::Formula1= new FileModel( "Models/formula1.obj");
// Models from points
const ModelDataBase* Models::Sphere= new ArrayModel( sphere, 2880);
const ModelDataBase* Models::Tree= new ArrayModel( tree, 92814);
const ModelDataBase* Models::Plain= new ArrayModel(plain, 6, true);
const ModelDataBase* Models::Suzi= new ArrayModel( suziSmooth, 2904);
const ModelDataBase* Models::Bushes= new ArrayModel(bushes, 8730);