#include <iostream>
#include <vector>

#include "libs/Tensor.h"

int main() {
  std::vector<int> sizes = {2, 2};
  auto type = novamind::DataType::kFLOAT;
  novamind::core::Tensor mytensor(sizes, type);
  auto itype = mytensor.get_datatype();
  //std::cout << itype << std::endl;
  return 0;
}
