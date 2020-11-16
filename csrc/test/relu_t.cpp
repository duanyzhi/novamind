#include <iostream>

#include "libs/activation.h"

int main() {
  novamind::operation::Activation noa;
  std::vector<int> sizes = {2, 2};
  auto type = novamind::DataType::kFLOAT;
  novamind::core::Tensor mytensor(sizes, type);

  float* new_data = static_cast<float*>(mytensor.data_ptr);
  print("befor relu:", new_data, 4);


  auto relu_tensor = noa.relu(mytensor);

  float* data = static_cast<float*>(relu_tensor.data_ptr);
  print("after relu:", data, 4);

  return 0;
}
