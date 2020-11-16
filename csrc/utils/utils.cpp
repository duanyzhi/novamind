#include <iostream>
#include <vector>

int GetVecNumel(std::vector<int> size_vec) {
  int numel = 1;
  for (unsigned int i = 0; i < size_vec.size(); i++) {
    numel = numel * size_vec[i];
  }
  return numel;
}