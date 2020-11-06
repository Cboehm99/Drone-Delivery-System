#ifndef DELIVERY_H_
#define DELIVERY_H_

#include "Drone.h"
#include "Customer.h"
#include "Package.h"

namespace csci3081 {

/*! Delivery
 */
class Delivery {
  //Essentially is just a container to store a set containing a customer, package, and drone
 public:

    Delivery();

    /*!
    Creates the Delivery container
    */
    Delivery(Customer* cust, Package* pack, Drone* drone);

    Customer* const GetCustomer();

    Drone* const GetDrone();

    Package* const GetPackage();

    void const GetRoute();

    void SetCustomer(Customer* customer);

    void SetDrone(Drone* drone);

    void SetPackage(Package* package);

    void NotifyObservers();

  private:
    Customer* customer_;
    Package* package_;
    Drone* drone_;
    std::Vector<EntityProject::EntityObserver*> Observers_; //Optimize in better data structure later
};

}  // namespace csci3081
#endif //PACKAGEFACTORY_H_
