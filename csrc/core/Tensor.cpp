#include <iostream>

#include "libs/Tensor.h"  // all *.h should write in Tensor.h

namespace novamind {

novamind::DataType novamind::Tensor::get_datatype() {
  return data_type;
}

Tensor::Tensor(std::vector<int> size, novamind::DataType datatype) :
  sizes(size), data_type(datatype)
{
  numel = GetVecNumel(size);
  switch(datatype) {
    case novamind::DataType::kFLOAT:
      {
        auto data = memory::allocateMemory<float>(numel);
        data_ptr = novamind::math::randn(data, numel, -1, 1);
        // data_ptr = (void*)data_randn;
        break;
      }
    case novamind::DataType::kINT:
      {
        data_ptr = (float*)memory::allocateMemory<int>(numel);
        std::cout << "INT TYPE should be covert." << std::endl;
        break;
      }
    default:
      data_ptr = nullptr;
      print("input novamind DataType is not support!");
      break;
  }
}

Tensor::~Tensor() {
  memory::freeMemory<void>(data_ptr);
}

// TODO(owner): add update data ptr
// void novamind::core::Tensor::update_data_ptr(float* new_data_ptr) {
//   // float* float_raw_data = memory::allocateMemory<float>(numel);
//   for (int i = 0; i < numel; i++) {
//     print("new:", new_data_ptr[i]);
//     data_ptr[i] = new_data_ptr[i];
//     print("aha:", data_ptr[i]);
//   }
//   // data_ptr = float_raw_data;
// }

}  // namespace novamind
