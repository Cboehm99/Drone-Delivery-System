#ifndef DRONE_SIMULATION_H_
#define DRONE_SIMULATION_H_


#include <EntityProject/ANVIL/drone_delivery_system.h>
#include <vector>
#include <string>
#include "json_helper.h"
#include "EntityFactory.h"
#include "Observer.h"

namespace csci3081 {


/* !\Drone Simulation
 */
class DroneSimulation : public entity_project::DroneDeliverySystem {
 public:
  /*!
    String& GetTeamName: returns the team name as a string variable.
  */
  const std::string& GetTeamName() const;

  /*!
    Entity* CreateEntity: Takes a picojson::object&, and is used to create
      entities such as drones, packages, and customers and inspects the json
      object thorugh a PrintEntityDetails function
  */
  entity_project::Entity* CreateEntity(const picojson::object& val);


  /*!
    Void AddEntity: Takes entity_project::Entity* and adds an entity
  */
  void AddEntity(entity_project::Entity* entity);

  // /*!
  //   Void ScheduleDelivery: Takes a entity_project::Package* and schedules
  //     a delivery using a customers destination and the json details associated
  //     with the package
  // */
  void ScheduleDelivery(entity_project::Package* package, entity_project::Customer* dest, const picojson::object& details);

  /*!
    Void AddObserver: Takes an entity_project::Entity* and entity_project::EntityObserver*,
      associates the observer with the entity, so that the interface can get
      notified of the location of the entity (drone/package/customer)
  */
  void AddObserver(entity_project::Entity* entity, entity_project::EntityObserver* observer);

  /*!
    Void AddObserver: Takes an entity_project::Entity* and entity_project::EntityObserver*,
      disassociates the observer with the entity (drone/package/customer)
  */
  void RemoveObserver(entity_project::Entity* entity, entity_project::EntityObserver* observer);

  /*!
    cons std::vector<entity_project>::Entity*>& GetEntities const:
      returns astd::Vector of Entity pointers for other methods to use
  */
  const std::vector<entity_project::Entity*>& GetEntities() const;

  /*!
    Void Update: Takes float dt, and updates the simulation every dt seconds
  */

  void Update(float dt);

  bool nearCustomer(Customer* customer);

protected:
  std::vector<EntityProject::EntityObserver*> observers_;

private:
  std::string teamName_ ;
  static IDCounter_ = 0;

};

}  // namespace csci3081


#endif  // DRONE_SIMULATION_H_
