#ifndef NOVAMIND_CSRC_ACTIVATION_H_
#define NOVAMIND_CSRC_ACTIVATION_H_

#include <iostream>

#include "libs/Tensor.h"
#include "libs/memory_allocator.h"
#include "libs/print.h"

namespace novamind {
namespace operation {

novamind::Tensor relu(novamind::Tensor tensor);

}  // namespace operation
}  // namespace novamind
#endif  // NOVAMIND_CSRC_ACTIVATION_H_
