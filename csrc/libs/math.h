#ifndef NOVAMIND_CSRC_MATH_H_
#define NOVAMIND_CSRC_MATH_H_

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

}  // namespace math
}  // namespace novamind
#endif  // NOVAMIND_CSRC_MATH_H_
