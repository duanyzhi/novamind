#include <iostream>

#include "libs/math.h"

int main() {
  novamind::math::BaseMathOp bmo(1027);
  auto num = bmo.getNum();
  std::cout << "num:" << num << std::endl;
  return 0;
}
