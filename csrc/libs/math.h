#ifndef NOVAMIND_CSRC_MATH_H_
#define NOVAMIND_CSRC_MATH_H_

#include <stdio.h>  /* printf */
#include <stdlib.h>  /* srand, rand */
namespace novamind {
namespace math {

class BaseMathOp {
 public:
  // default constructor
  BaseMathOp(int n);
  //~BaseMathOp();
  int getNum();
 private:
  int num;
};

inline float* randn(float* data_ptr, int numel, float start_num=0.0, float end_num=1.0) {
  // generate float random number between start num to end num
  float diff = end_num - start_num;
  for (int i = 0; i < numel; i++) {
    auto random = (float) rand() / (float)RAND_MAX;
    float gen_num = random * diff + start_num;
    data_ptr[i] = static_cast<float>(gen_num);
  }
  return data_ptr;
}

}  // namespace math
}  // namespace novamind

#endif  // NOVAMIND_CSRC_MATH_H_
