#include "libs/activation.h"

namespace novamind {
namespace operation {

novamind::Tensor relu(novamind::Tensor tensor) {
  auto data = static_cast<float*>(tensor.data_ptr);
  float* relu_out_data = novamind::allocateGlobalBuffer<float>(tensor.numel);
  for (int i = 0; i < tensor.numel; i++) {
    relu_out_data[i] = data[i] < 0 ? -1 * data[i] : data[i];
  }

  novamind::Tensor relu_out_tensor(tensor.sizes,
                                   tensor.get_datatype(),
                                   relu_out_data);
  return relu_out_tensor;
}

}  // namespace operation
}  // namespace novamind
