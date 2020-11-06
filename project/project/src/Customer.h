#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <EntityProject/ANVIL/Customer.h>
#include "json_helper.h"

namespace csci3081 {

/*! Customer Class
 */
class Customer : public entity_project::Customer {
public:
  /*!
  Constructor to initiate the Customer type
  */
  Customer();

  int const GetId();

  std::string const GetName();

  float* const GetPosition();

  float* const GetDirection();

  float const GetRadius();

  int const GetVersion();

  std::string const GetType();

  void SetPosition(float[3] pos);

  void SetDetails(picojson::object& details);

  void SetDirection(float[3] dir);

  // bool isSource();
  //
  // bool isDestination();
  //
  // void setPackage();

  ~Customer();

private:
  string type_;
  bool hasPackage;
  bool SourceOrDestination;
  static int idCounter = 20000;
};

}  // namespace csci3081

#endif
