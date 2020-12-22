#include <iostream>

#include "libs/ops.h"

int main() {
  std::vector<int> sizes = {2, 2};
  auto type = novamind::DataType::kFLOAT;
  novamind::Tensor mytensor(sizes, type);

  float* new_data = static_cast<float*>(mytensor.data_ptr);
  print("befor relu:", new_data, 4);


  auto relu_tensor =  novamind::relu(mytensor);

  float* data = static_cast<float*>(relu_tensor.data_ptr);
  print("after relu:", data, 4);

  return 0;
}
