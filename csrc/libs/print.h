#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "libs/type.h"

// template must be in *.h
template<class T>
inline void print(std::string str, T num) {
  std::cout << str << num << std::endl;
}

inline void print(std::string str) {
  std::cout << str << std::endl;
}

template<class T>
inline void print(std::string str,
                  std::vector<T> vec,
                  int start_index = 0,
                  int end_index = 1) {
  assert(end_index <= vec.size() && "end index must be less than vector size"); 
  std::cout << "===========================" << std::endl;
  std::cout << str << std::endl;
  for (int i = start_index; i < end_index; i++) {
    std::cout << i << " : " << vec[i] << std::endl;
  }
  std::cout << "===========================" << std::endl;
}

inline void print(std::string str, novamind::DataType datatype) {
  switch(datatype) {
    case novamind::DataType::kFLOAT:
      std::cout << str << "novamind::DataType::kFLOAT" << std::endl;
      break;
    case novamind::DataType::kINT:
      std::cout << str << "novamind::DataType::kINT" << std::endl;
      break;
    default:
      std::cout << "datatype is not support!" << std::endl;
      break;
  }
}

template<class T>
inline void print(std::string str, T* data, int numel) {
  std::cout << str << std::endl;
  for (int i = 0; i < numel; i++) {
    std::cout << data[i] << std::endl;
  }
}
