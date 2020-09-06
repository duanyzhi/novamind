#ifndef NOVAMIND_CSRC_CORE_TENSOR_H_
#define NOVAMIND_CSRC_CORE_TENSOR_H_

#include <iostream>
#include <vector>

#include "libs/type.h"

namespace novamind {
namespace core {

class BaseTensor {
 public:
  // default constructor
  //BaseTensor();

  //std::string tensor_name;
  
 private:
  std::string tensor_name = "Base Tensor";
  
};

class Tensor : public BaseTensor {
 public:
   Tensor(std::vector<int> size, novamind::DataType datatype) : 
       sizes(size), data_type(datatype) { };
   std::string type;
   novamind::DataType get_datatype();
 private:
  std::vector<int> sizes;
  novamind::DataType data_type;
};

}  // namespace core
}  // namespace novamind
#endif  // NOVAMIND_CSRC_CORE_TENSOR_H_
