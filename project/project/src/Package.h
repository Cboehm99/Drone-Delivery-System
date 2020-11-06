#ifndef PACKAGE_H_
#define PACKAGE_H_

#include <EntityProject/ANVIL/package.h>

namespace csci3081 {


/*! Package Class

 */
class Package : public entity_project::Package {
 public:
    /*!
    Constructor to initiate the Package type
    */
    Package();

    int const GetId();

    std::string const GetName();

    float* const GetPosition();

    float* const GetDirection();

    float const GetRadius();

    int const GetVersion();

    std::string const GetType();

    void SetPosition(float[3] pos);

    void SetDetails(picojson::object& details);

    void SetDirection(float[3] direction);

    // bool IsDynamic();

    ~Package();

private:
  string type_;
  bool scheduled;
  bool enRoute;
  bool delivered;
};

}  // namespace csci3081
#endif
