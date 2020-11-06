#include <EntityProject/ANVIL/drone_delivery_system.h>
#include <vector>
#include <string>
#include "src/json_helper.h"
#include "Observer.h"
#include "AddEntities.h"

using namespace csci3081;


/*!
  String& GetTeamName: returns the team name as a string variable.
*/
const std::string& GetTeamName() const {
  return teamName_;
}

/*!
  Entity* CreateEntity: Takes a picojson::object&, and is used to create
    entities such as drones, packages, and customers and inspects the json
    object thorugh a PrintEntityDetails function
*/
entity_project::Entity* CreateEntity(const picojson::object& val) {
  AddEntities implem = AddEntities();
  return implem.AddEntity(val);
}

/*!
  Void AddEntity: Takes entity_project::Entity* and adds an entity
*/
void AddEntity(entity_project::Entity* entity) {
  entity->SetID(IDCounter_);
  IDCounter_++;
  entites_.push_back(entity);
}

/*!
  Void ScheduleDelivery: Takes a entity_project::Package* and schedules
    a delivery using a customers destination and the json details associated
    with the package
*/
void ScheduleDelivery(entity_project::Package* package, entity_project::Customer* dest, const picojson::object& details) {
  DeliveryManager DeliveryManager = DeliveryManager();
  DeliveryManager.ScheduleDelivery(package, customer);
}

/*!
  Void AddObserver: Takes an entity_project::Entity* and entity_project::EntityObserver*,
    associates the observer with the entity, so that the interface can get
    notified of the location of the entity (drone/package/customer)
*/
void AddObserver(entity_project::Entity* entity, entity_project::EntityObserver* observer) {

}

/*!
  Void AddObserver: Takes an entity_project::Entity* and entity_project::EntityObserver*,
    disassociates the observer with the entity (drone/package/customer)
*/
void RemoveObserver(entity_project::Entity* entity, entity_project::EntityObserver* observer) {

}

/*!
  cons std::vector<entity_project>::Entity*>& GetEntities const:
    returns astd::Vector of Entity pointers for other methods to use
*/
const std::vector<entity_project::Entity*>& GetEntities() const { return entities_; }

/*!
  Void Update: Takes float dt, and updates the simulation every dt seconds
*/
void Update(float dt) {
  DeliveryManager deliveryManager;
  deliveryManager.Update(dt);
}
