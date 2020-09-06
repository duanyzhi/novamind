#include <iostream>

#include "libs/Tensor.h"

namespace novamind {
namespace core {

novamind::DataType novamind::core::Tensor::get_datatype() {
  return data_type;
}

}  // namespace core
}  // namespace novamind
