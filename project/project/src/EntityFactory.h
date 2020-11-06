#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_

#include <EntityProject/ANVIL/Entity.h>
#include "Drone.h"
#include "Customer.h"
#include "Package.h"

namespace csci3081 {

/*! Entity Abstract Factory
 */
class EntityFactory {
 public:
    /*!
    Constructor to initiate the AbstractFactory type
    */
    virtual EntityProject::Entity* CreateEntity(picojson::object& details);

    virtual Drone* CreateDrone(picojson::object& details);

    virtual Package* CreateDrone(picojson::object& details);

    virtual Customer* CreateDrone(picojson::object& details);
};

}  // namespace csci3081
#endif
