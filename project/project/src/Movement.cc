#include <EntityProject/ANVIL/Entity.h>
#include <EntityProject/EntityObserver.h>
#include <EntityProject/simple_UMN_route_manager.h>
#include <EntityProject/simple_UMN_route_points.h>
#include <vector>
#include "Drone.h"
#include "Package.h"
#include "Customer.h"
#include "Delivery.h"
#include "Movement.h"

using namespace csci3081;
Movement::Movement(){
  RouteManager_ = new simpleUMNRouteManager;
}

void Movement::Router(Drone* drone, EntityProject::Entity* dest) {
  float x,y,z;
  std::vector<float> sourcePos = drone.GetPosition();
  x = sourcePos.at(0);
  y = sourcePos.at(1);
  z = sourcePos.at(2);
  EntityProject::simpleUMNRoutePoint drone = EntityProject::simpleUMNRoutePoint(x,y,z);

  std::vector<float> sourcePos = destination.GetPosition();
  x = destinationPos.at(0));
  y = destinationPos.at(1));
  z = destinationPos.at(2));
  EntityProject::simpleUMNRoutePoint dest = EntityProject::simpleUMNRoutePoint(x,y,z);
  drone->.SetRoute(routeManager_.GetRoute(drone, dest));
}

void Movement::Update(Delivery delivery, float speed) {
  //Initilization Bloc
  std::vector<EntityProject::simpleUMNRoutePoint> route = drone->GetRoute();
  EntityProject::simpleUMNRoutePoint* waypoint = = route.front();
  Drone* drone = delivery.GetDrone();
  Package* package = delivery.GetPackage();
  Customer* customer = delivery.GetCustomer();
  float distance = droneRoutePoint.GetDistance(&waypoint);;
  float[3] dronePos = drone->GetPositon();
  EntityProject::simpleUMNRoutePoint droneRoutePoint  = EntityProject::simpleUMNRoutePoint(dronePos[0], dronePos[1], dronePos[2]);
  bool hitPackage = distance + package->GetRadius() < speed + customer->GetRadius();
  bool hitDrone =  distance + drone->GetRadius() < speed + customer->GetRadius();
  bool droneHitPackage = distance + drone->GetRadius() < speed + package->GetRadius();
  Movement mover = Movement();

  if (route.size() ==1 && !drone->HasPackage() && droneHitPackage) {
    //is travelling to pickup package
    float distToMove = distance - package->GetRadius() - customer->GetRadius();
    for(float i : dronePos) {
      i += distToMove;
    }
    drone->SetPosition(dronePos);
    drone->SetHasPackage(true);
    package->SetPosition(dronePos);
    Movement.Router(drone, customer);
    return;
  }
  else if (route.size() == 1 && (hitPackage || hitDrone)) { //dropoff approach
    DeliveryManager deliveryManager;
    if (hitPackage) {
      float distToMove = distance - package->GetRadius() - customer->GetRadius();
    }
    else {
      float distToMove = distance - drone->GetRadius() - customer->GetRadius();
    }

    for(float i : dronePos) {
      i += distToMove;
    }
    drone->SetPosition(dronePos);
    package->SetPosition(dronePos);
    drone->SetRoute(NULL);
    drone->SetHasPackage(false);
    deliveryManager.DropoffPackage();
    return;
  }

  if (distance =< (speed)) { //Hit a waypoint
    float speedLeft = speed - distance;

    drone->SetPosition(waypoint[0], waypoint[1], waypoint[2]);
    route.erase(0);
    drone->SetRoute(route);
    mover.Update(delivery, speedLeft);
  }
  else { //Between waypoints
    for(float i : dronePos) {
      i += speed;
    }
    drone->SetPosition(dronePos);
    package->SetPosition(dronePos);
  }
}
