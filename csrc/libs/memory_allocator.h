#pragma once

#include <iostream>
#include <assert.h>
#include <unordered_set>

namespace novamind {
namespace memory {

// malloc once
template <typename T>
inline T* allocateMemory(int64_t size) {
  T* data_ptr = static_cast<T*>(malloc(size * sizeof(T)));
  assert(data_ptr != nullptr);
  return data_ptr;
}


// free once
template <typename T>
inline void freeMemory(T* buffer) {
  if (buffer) {
    free(buffer);
  }
}


// Memory Class
class MemoryAllocator {
 public:
  MemoryAllocator();
  ~MemoryAllocator();

  template <typename T>
  T* allocate(int64_t size) {
    auto data_ptr = allocateMemory<T>(size);
    ptr_set.insert(static_cast<void*>(data_ptr));
    return data_ptr;
  }

  // Free the specified buffer
  template <typename T>
  void deallocate(T* buffer) {
    if (ptr_set.find(static_cast<void*>(buffer)) != ptr_set.end()) {
      freeMemory<T>(buffer);
      ptr_set.erase(static_cast<void*>(buffer));
    }
  }

  void destructors();

 private:
  std::unordered_set<void*> ptr_set;
};


}  // namespace memory


template <typename T>
T* allocateGlobalBuffer(int64_t size) {
  return memory::MemoryAllocator().allocate<T>(size);
}

template <typename T>
void freeGlobalBuffer(T* buffer) {
  //memory::MemoryAllocator::instance().deallocate<T>(buffer);
  memory::MemoryAllocator().deallocate<T>(buffer);
}


}  // namespace novamind
