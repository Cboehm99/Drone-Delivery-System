#include <EntityProject/ANVIL/Entity.h>
#include <EntityProject/ANVIL/drone.h>
#include "Drone.h"
#include "json_helper.h"

using namespace csci3081;

Drone::Drone() {
  AddType<Drone>();
  name_ = NULL;
  type_ = "customer";
  details_ = NULL;
  position_ = NULL;
  direction_ = NULL;
  radius_ = NULL;
  speed_ = NULL;
  type_ = "drone";
  availabale_ = false;
  isWithinRadius_ = false;
  route_ = NULL;

  Drone* pointer = &this;
  drones_.push_back(pointer)
}

float const Drone::GetSpeed() {
  return speed_;
}

int const Drone::GetId() {
  return id_;
}

std::string const Drone::GetName() {
  return name_;
}

float* const Drone::GetPosition() {
  return position_;
}

float* const Drone::GetDirection() {
  return direction_;
}

float* const Drone::GetVelocity() {
  return velocity_;
}

float const Drone::GetRadius() {
  return raidus_;
}

int const Drone::GetVersion() {
  return version_;
}

bool const Drone::GetAvailability() {
  return availabale_;
}

bool const Drone::HasPackage() {
  return hasPackage_;
}

std::vector<EntitySystem::simpleUMNRoutePoint> const GetRoute(){
  return route_;
}

void drone::SetHasPackage(bool hasPackage) {
  hasPackage_ = hasPackage;
}

void Delivery::SetRoute(std::vector<EntitySystem::simpleUMNRoutePoint> route) {
  route_ = route;
}

void Drone::SetAvailability(bool availabale) {
  availabale_ = availabale;
}

void Drone::IsWithinRadius(bool isWithinRadius) {
  isWithinRadius_ = isWithinRadius;
}

void Drone::SetPosition(float[] input) {
  // May need input verification later
  position_[0] = input[0];
  position_[1] = input[1];
  position_[2] = input[2];
}


std::string const Drone::GetType() {
  return type_;
}

void Drone::setDetails(picojson::object& obj) {
  //hasPackage must be False to be able to run, as a safeguard
  if(hasPackage_!) {
    json_helper jhelp;

    details_ = &details;
    name_ = jhelp.GetString(&details, "name");
    speed_ = static_cast<float>(jhelp.GetObject(&details, "speed"));
    position_ = jhelp.GetArray(&details, "position");
    direction_ = jhelp.GetArray(&details, "direction");
    radius_ = static_cast<float>(jhelp.GetObject(&details, "radius"));
    type_ = "drone";
    Drone* drone;
  }
}

void Drone::setID(int id) {
  id_ = id;
}

void Drone::SetDirection(float[] input) {
  direction_[0] = input[0];
  direction_[1] = input[1];
  direction_[2] = input[2];
}


Drone::~Drone(){
  delete[] position_;
  delete[] direction_;

  Drone* drone = &this;
  drones_.erase(drones_.find(this))
  drone = NULL;
}
