#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include <EntityProject/ANVIL/Entity.h>
#include <EntityProject/EntityObserver.h>
#include <EntityProject/simple_UMN_route_manager.h>
#include <EntityProject/simple_UMN_route_points.h>
#include <vector>
#include "DroneSimulation.h"
#include <EntityProject/EntityObserver.h>
#include <vector>
#include "Drone.h"
#include "Package.h"
#include "Customer.h"
#include "Delivery.h"

namespace csci3081 {

/*! Class: Movement
*/

class Movement : protected DroneSimulation {
  /*! Will be utilized more in future iterations with realistic routing and
  velocity calculations
  */

  Movement();

  void Router(Drone* drone, EntityProject::Entity* dest);

  void Update(Delivery delivery, float speed);

private:
  EntityProject::simpleUMNRouteManager routeManager_;
};

#endif
}
