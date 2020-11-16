#include <iostream>
#include <vector>

#include "libs/Tensor.h"
#include "libs/novamind.h"

int main() {
  std::vector<int> sizes = {2, 2};
  auto type = novamind::DataType::kFLOAT;
  novamind::core::Tensor mytensor(sizes, type);
  auto itype = mytensor.get_datatype();
  auto data = static_cast<float*>(mytensor.data_ptr);
  print("type:", itype);
  print("data:", data, 4);
  return 0;
}
