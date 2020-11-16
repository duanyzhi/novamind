#ifndef NOVAMIND_CSRC_ACTIVATION_H_
#define NOVAMIND_CSRC_ACTIVATION_H_

#include <iostream>

#include "libs/Tensor.h"
#include "libs/memory_allocator.h"
#include "libs/print.h"

namespace novamind {
namespace operation {

class Activation {
 public:
  // default constructor
  //Activation();
  //~Activation();

  // act function
  novamind::core::Tensor relu(novamind::core::Tensor tensor);
 private:
  std::string op_name;
};

}  // namespace operation
}  // namespace novamind
#endif  // NOVAMIND_CSRC_ACTIVATION_H_
