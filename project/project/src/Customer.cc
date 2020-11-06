#include <EntityProject/ANVIL/customer.h>
#include "json_helper.h"
#include "Customer.h"

using namespace csci3081;

Customer::Customer() {
  AddType<Customer>();
  details_ = NULL;
  position_ = NULL;
  direction_ = NULL;
  radius_ = NULL;
  name_ = NULL;
  type_ = "customer";
}

int const Customer::GetId() {
  return id;
}

std::string const Customer::GetName() {
  return name;
}

float* const Customer::GetPosition() {
  return position;
}

float* const Customer::GetDirection() {
  return direction;
}

float const Customer::GetRadius() {
  return raidus;
}

int const Customer::GetVersion() {
  return version;
}

std::string const Customer::GetType() {
  return type_;
}

void Customer::setPosition(float[3] pos) {
  position_[0] = pos[0];
  position_[1] = pos[1];
  position_[2] = pos[2];
}

void Customer::setDetails(picojson::object& obj) {
  json_helper jhelp;

  details_ = &details;
  name_ = jhelp.GetString(&details, "name");
  speed_ = static_cast<float>(jhelp.GetObject(&details, "speed"));
  position_ = jhelp.GetArray(&details, "position");
  direction_ = jhelp.GetArray(&details, "direction");
  radius_ = static_cast<float>(jhelp.GetObject(&details, "radius"));
  type_ = "package";
}

void Customer::SetDirection(float[3] direction){
  direction_[0] = direction[0];
  direction_[1] = direction[1];
  direction_[2] = direction[2];
}

void Customer::setID(int id) {
  id_ = id;
}

std::string Customer::GetType() {
  return type_;
}

// bool Customer::IsSource(){
//   return SourceOrDestination;
// }
//
// bool Customer::IsDestination(){
//   return !SourceOrDestination;
// }

Customer::~Customer(){
  delete[] position_;
  delete[] direction_;
}
