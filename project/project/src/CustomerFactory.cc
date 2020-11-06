#include "CustomerFactory.h"

using namespace csci3081;

CustomerFactory::CustomerFactory();

Entity* CustomerFactory::CreateEntity(picojson::object& details) {
  Customer* newCustomer = new Customer();
  *newCustomer.SetDetails(object& details);
  return newCustomer;
}
