#include <EntityProject/EntityObserver.h>
#include "Drone.h"
#include "Customer.h"
#include "Package.h"

using namespace csci3081;

Delivery::Delivery() : customer_(NULL), package_(NULL), drone_(NULL);

Delivery::Delivery(Customer* cust, Package* pack, Drone* drone) : customer_(cust), package_(pack), drone_(drone);

Customer* const Delivery::GetCustomer() {
  return customer;
}

Drone* const Delivery::GetDrone() {
  return drone_;
}

Package* const Delivery::GetPackage() {
  return package_;
}

void Delivery::SetCustomer(Customer* customer) {
  customer_ = customer;
}

void Delivery::SetPackage(Package* package) {
  package_ = package;
}

void Delivery::SetDrone(Drone* drone) {
  drone_ = drone;
}

void const Delivery::GetRoute() {
  return route_;
}

void Delivery::AddObserver(EntityProject::Observer* observer){
  observers_.push_back(observer);
}

void Delivery::RemoveObserver(EntityProject::Observer* observer) {
  observers_.erase(observers_.find(observer));
}
//
// void Delivery::NotifyObservers() {
//   for(Observer* i : observers_) {
//     i->Update();
//   }
// }
