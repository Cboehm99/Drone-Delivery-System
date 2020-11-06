#include "Package.h"

using namespace csci3081;

Package::Package() {
  AddType<Package>();
  details_ = NULL;
  position_ = NULL;
  direction_ = NULL;
  radius_ = NULL;
  name_ = NULL;
  id_ = idCounter;
  idCounter++;
}

int const Package::GetId() {
  return id;
}

std::string const Package::GetName() {
  return name;
}

float* const Package::GetPosition() {
  return position;
}

float* const Package::GetDirection() {
  return direction;
}

float const Package::GetRadius() {
  return raidus;
}

int const Package::GetVersion() {
  return version;
}

std::string const Package::GetType() {
  return type_;
}

// bool Package::IsScheduled() {
//   return
// }
// void Package::NotifyObserver();
// bool Package::IsEnRoute();
//
// bool Package::IsDelivered();

void Package::SetPosition(float[3] pos) {
  position_[0] = pos[0];
  position_[1] = pos[1];
  position_[2] = pos[2];
}

void Package::SetDetails(picojson::object& obj) {
  json_helper jhelp;

  details_ = &details;
  name_ = jhelp.GetString(&details, "name");
  speed_ = static_cast<float>(jhelp.GetObject(&details, "speed"));
  position_ = jhelp.GetArray(&details, "position");
  direction_ = jhelp.GetArray(&details, "direction");
  radius_ = static_cast<float>(jhelp.GetObject(&details, "radius"));
  type_ = "package";
}

void Package::SetDirection(float[3] direction){
  direction_[0] = direction[0];
  direction_[1] = direction[1];
  direction_[2] = direction[2];
}

void Package::setID(int id) {
  id_ = id;
}

~Package::Package() {
  delete[] position;
  delete[] direction;
}
