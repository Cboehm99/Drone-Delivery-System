#ifndef ADDENTITIES_H_
#define ADDENTITIES_H_

#include "json_helper.h"
#include "DroneFactory.h"
#include "PackageFactory.h"
#include "CustomerFactory.h"
#include <EntityProject/ANVIL/Entity.h>

namespace csci3081 {

/*! Entity Abstract Factory
 */
class AddEntities {
 public:
    /*!
    Constructor to initiate the AddEntities type
    */
    AddEntities();

    EntityProject::Entity* AddEntity(picojson::object& details);
};

}  // namespace csci3081
#endif
