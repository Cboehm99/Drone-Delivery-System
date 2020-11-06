#ifndef CUSTOMERFACTORY_H_
#define CUSTOMERFACTORY_H_

#include <EntityProject/ANVIL/Entity.h>
#include "CustomerFactory.h"
#include "Customer.h"

namespace csci3081 {

/*! CustomerFactory
 */
class CustomerFactory : public csci3081::EntityFactory {
 public:
    /*!
    Constructor to initiate the CustomerFactory type
    */
    CustomerFactory();

    EntityProject::Entity* CreateEntity(picojson::object& details);
};

}  // namespace csci3081
#endif
