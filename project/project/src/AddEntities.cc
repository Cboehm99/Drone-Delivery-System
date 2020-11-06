#include "json_helper.h"
#include "DroneFactory.h"
#include "PackageFactory.h"
#include "CustomerFactory.h"
#include "AddEntities.h"
#include <EntityProject/ANVIL/Entity.h>


using namespace csci3081;
/*! Entity Abstract Factory
 */
    /*
    Constructor to initiate the AddEntities type
    */
AddEntities::AddEntities();

EntityProject::Entity* AddEntities::AddEntity(picojson::object& details) {
  json_helper jHelp;
  std::string typename = jHelp.GetString(details);
  switch typename:
    case "drone":
      factory = new DroneFactory();
      EntityProject::Entity* temp;
      temp = factory.CreateEntity(details);
      delete factory;
      return temp;
      break;
    case "customer":
      factory = new CustomerFactory();
      EntityProject::Entity* temp;
      temp = factory.CreateEntity(details);
      delete factory;
      return temp;
      break;
    case "package":
      factory = new PackageFactory();
      EntityProject::Entity* temp;
      temp = factory.CreateEntity(details);
      delete factory;
      return temp;
      break;
    default:
      return NULL;
      break;
}
