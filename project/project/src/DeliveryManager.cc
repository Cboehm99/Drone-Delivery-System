#include <EntityProject/ANVIL/Entity.h>
#include <vector>
#include <string>
#include "Observer.h"
#include "DroneSimulation.h"
#include "Movement.h"

using namespace csci3081;

DeliveryManager::DeliveryManager() {
  int size = entities.size();
  for(int i(0); i < size; i++) { //initialize drones_, customers_, packages_std::Vectors
    EntityProject::Entity* entity = entities.at(i);
    std::string typename = entity->GetType()
    switch typename:
      case "drone":
        entity->asType<Drone>;
        drones_.push_back(entity)
        break;
      case "customer":
        entity->asType<Customer>;
        customers_.push_back(entity)
        break;
      case "package":
        entity->asType<package>;
        packages_.push_back(entity)
        break;
      default:
        //Future Error
        break;
  }
}

void DeliveryManager::ScheduleNewDelivery(Package* package, Customer* customer) {
  Drone* drone;
  Delivery delivery;
  Movement mover;

  drone = AssignDrone();
  delivery = Delivery(package, customer, drone);
  deliveries_.push_back(delivery);
  mover.Router(drone, package);
}

void DeliveryManager::DropoffPackage(Delivery delivery) {
  delivery.GetDrone()->SetAvailability(True);
  deliveries_.erase(deliveries_.find(delivery))
  observers_->OnEvent();
}

Drone* DelvieryManager::AssignDrone() {
  bool availabale = false;
  int iter = 0;
  int size = drones_.size();
  while(!availabale && iter < size) {
    Drone* drone = drones_.at(iter);
    if (drone->GetAvailability()) {
      drone->SetAvailability(false);
      return Drone;
    }
  }
}


void DeliveryManager::Update(float dt) {
  for(Delivery i : deliveries_) {
    Movement mover;
    mover.update(i, dt)
  }
  for(EntityProject::EntityObserver i : observers_) {
    i->OnEvent();
  }
}
