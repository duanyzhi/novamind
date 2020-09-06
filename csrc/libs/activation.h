#ifndef NOVAMIND_CSRC_ACTIVATION_H_
#define NOVAMIND_CSRC_ACTIVATION_H_

#include <iostream>

namespace novamind {
namespace operation {

class Activation {
 public:
  // default constructor
  //Activation();
  //~Activation();

  // act function
  void relu();
 private:
  std::string op_name;
};

}  // namespace operation
}  // namespace novamind
#endif  // NOVAMIND_CSRC_ACTIVATION_H_
