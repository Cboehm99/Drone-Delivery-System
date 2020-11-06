#include "DroneFactory.h"
#include "Drone.h"
#include <EntityProject/ANVIL/Entity.h>

using namespace csci3081;

DroneFactory::DroneFactory();

Entity* DroneFactory::CreateEntity(picojson::object& details) {
  Drone* newDrone = new Drone();
  *newDrone.SetDetails(object& details);
  return newDrone;
}
