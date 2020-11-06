#ifndef DELIVERYMANAGER_H_
#define DELIVERYMANAGER_H_

#include <EntityProject/ANVIL/Entity.h>
#include <EntityProject/EntityObserver.h>
#include <vector>
#include <string>
#include "src/json_helper.h"
#include "Drone.h"
#include "Package.h"
#include "Delivery.h"
#include "DroneSimulation.h"

namespace csci3081 {

/*! DeliveryManager
 */

 class DeliveryManager : protected DroneSimulation {
  public:
    /*!
      Void DeliveryManagerDelivery: Takes a entity_project::Package* and DeliveryManagers
        a delivery using a customers destination and the json details associated
        with the package
    */
    DeliveryManager();

    void ScheduleNewDelivery(Package* package, Customer* customer);

    void DropoffPackage(Delivery delivery);

    Drone* AssignDrone();

    void Update(float dt);

  protected:
   std::vector<Delivery> deliveries_;
 };

 }  // namespace csci3081


 #endif
