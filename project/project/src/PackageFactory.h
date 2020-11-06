#ifndef PACKAGEFACTORY_H_
#define PACKAGEFACTORY_H_

#include <EntityProject/ANVIL/Entity.h>
#include "EntityFactory.h"

namespace csci3081 {

/*! PackageFactory
 */
class PackageFactory : public csci3081::EntityFactory {
 public:
    /*!
    Constructor to initiate the PackageFactory type
    */
    PackageFactory::PackageFactory();

    EntityProject::Entity* CreateEntity(value picojson::object& details);
};

}  // namespace csci3081
#endif //PACKAGEFACTORY_H_
