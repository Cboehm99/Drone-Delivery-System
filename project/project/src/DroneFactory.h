#ifndef DRONEFACTORY_H_
#define DRONEFACTORY_H_

#include <EntityProject/ANVIL/DroneFactory.h>
#include "EntityFactory.h"

namespace csci3081 {

/*! DroneFactory
 */
class DroneFactory : public csci3081::EntityFactory {
 public:
    /*!
    Constructor to initiate the DroneFactory type
    */
    DroneFactory();

    EntityProject::Entity* CreateEntity(picojson::object& details);
};

}  // namespace csci3081
#endif
