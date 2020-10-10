#include "libs/activation.h"
#include "libs/memory_allocator.h"

namespace novamind {
namespace operation {

void Activation::relu() {
  std::cout << "---------  relu  ----------" << std::endl; 
  float* relu_data = allocateGlobalBuffer<float>(10);
  relu_data[0] = 1.0;
  relu_data[1] = 2.0;
  relu_data[9] = 9.0;
  std::cout << "relu data:" << relu_data[9] << std::endl;
}

}  // namespace operation
}  // namespace novamind
