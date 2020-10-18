#include <iostream>

#include "libs/Tensor.h"
#include "libs/memory_allocator.h"
#include "libs/utils.h"
#include "libs/math.h"


namespace novamind {
namespace core {

novamind::DataType novamind::core::Tensor::get_datatype() {
  return data_type;
}

Tensor::Tensor(std::vector<int> size, novamind::DataType datatype) :
  sizes(size), data_type(datatype)
{
  int numel = 1;
  for (int i = 0; i < size.size(); i++) {
    numel = numel * size[i];
  }
  switch(datatype) {
    case novamind::DataType::kFLOAT:
      {
        auto data = memory::allocateMemory<float>(numel);
        float* data_randn = novamind::math::randn(data, numel);
        data_ptr = (void*)data_randn;
        break;
      }
    case novamind::DataType::kINT:
      {
        data_ptr = (void*)memory::allocateMemory<int>(numel);
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

}  // namespace core
}  // namespace novamind
