#include "libs/ops.h"

namespace novamind {

#define KERNEL_DISPATCH(OP_NAME, ...)                         \
  auto&& result = novamind::operation::OP_NAME(__VA_ARGS__);  \
  return result;                                              \

#define ERROR_DISPATCH(OP_NAME, ...)                          \
  std::cout << OP_NAME << "dispatch error." << "\n";          \
  throw std::exception();                                     \

#define DISPATCH(OP_NAME, ...)                                \
  try {                                                       \
    KERNEL_DISPATCH(OP_NAME, __VA_ARGS__);                    \
  } catch (std::exception& e) {                               \
    ERROR_DISPATCH(OP_NAME, __VA_ARGS__);                     \
  }                                                           \

novamind::Tensor relu(novamind::Tensor tensor) {
  DISPATCH(relu, tensor);
}

}  // namespace novamind
