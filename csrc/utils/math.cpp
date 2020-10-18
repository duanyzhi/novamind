#include <iostream>

#include "libs/math.h"
#include "libs/Tensor.h"

namespace novamind {
namespace math {

BaseMathOp::BaseMathOp(int n) : num(n) {}

int BaseMathOp::getNum() {
  std::cout << "BaseMathOp::getNum" << std::endl; 
  return num;
}

//core::Tensor randn(std::vector<int> size, novamind::DataType type) {
//  novamind::core::Tensor randn_tensor(size, type);
//  return randn_tensor;
//}
//
}  // namespace math
}  // namespace novamind
