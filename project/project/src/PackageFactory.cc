#include "PackageFactory.h"
#include <EntityProject/ANVIL/Entity.h"
using namespace csci3081;

PackageFactory::PackageFactory() {}

Entity* PackageFactory::CreateEntity(picojson::object& details) {
  Package* newPackage = new Package();
  *newPackage.SetDetails(object& details);
  return newPackage;
}
