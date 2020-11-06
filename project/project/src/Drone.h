#ifndef DRONE_H_
#define DRONE_H_

#include <EntityProject/ANVIL/drone.h>

namespace csci3081 {

/*! Drone
 */
class Drone : public entity_project::Drone {
 public:
    /*!
    Constructor to initiate the Drone type
    */
    Drone();

    int const GetId();

    std::string const GetName();

    float* const GetPosition();

    float* const GetDirection();

    float* const GetVelocity();

    float const GetRadius();

    int const GetVersion();

    std::vector<EntitySystem::simpleUMNRoutePoint> const GetRoute();

    std::string const GetType();

    bool const HasPackage();

    bool const GetAvailability();

    void SetAvailability(bool availabale);

    void SetPosition(float[] pos);

    void SetDetails(picojson::object& details);

    void SetIsWithinRadius(bool isWithinRadius);

    void SetDirection(float[] dir);

    void SetRoute(std::vector<EntitySystem::simpleUMNRoutePoint> route);


    void SetHasPackage(bool hasPackage);

    ~Drone();

private:
  float speed_;
  string type_;
  bool availabale_;
  bool hasPackage_;
  float[3] velocity_;
  std::vector<EntityProject::simpleUMNRoutePoint*> route_;
  static std::vector<Drone*> drones_;
};

}  // namespace csci3081
#endif
