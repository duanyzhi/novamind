#ifndef NOVAMIND_CSRC_CORE_TENSOR_H_
#define NOVAMIND_CSRC_CORE_TENSOR_H_

#include <iostream>
#include <vector>

#include "libs/type.h"

#include "libs/memory_allocator.h"
#include "libs/novamind.h"
#include "libs/math.h"

namespace novamind {
namespace core {

class BaseTensor {
 public:
  // default constructor
  // BaseTensor();

  // std::string tensor_name;
  
 private:
  std::string tensor_name = "Base Tensor";
  
};

class Tensor : public BaseTensor {
 public:
  Tensor(std::vector<int> size, novamind::DataType datatype);
  Tensor(std::vector<int> size, novamind::DataType datatype, float* data_ptr_) :
    sizes(size), data_type(datatype), data_ptr(data_ptr_) {};
  ~Tensor();
  std::string type;
  novamind::DataType get_datatype();
  std::vector<int> sizes;
  int numel;
  float* data_ptr;
  void update_data_ptr(float* new_data_ptr);
 private:
  novamind::DataType data_type;
};

}  // namespace core
}  // namespace novamind
#endif  // NOVAMIND_CSRC_CORE_TENSOR_H_
