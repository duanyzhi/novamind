#include <iostream>

#include "libs/math.h"

namespace novamind {
namespace math {

BaseMathOp::BaseMathOp(int n) : num(n) {}

int BaseMathOp::getNum() {
  std::cout << "BaseMathOp::getNum" << std::endl; 
  return num;
}

}  // namespace math
}  // namespace novamind
