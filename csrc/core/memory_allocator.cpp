#include "libs/memory_allocator.h"


namespace novamind {
namespace memory {

// constructor
MemoryAllocator::MemoryAllocator() {}

// destructors
MemoryAllocator::~MemoryAllocator() { destructors(); };

// implement of destructors
void MemoryAllocator::destructors() {
  std::cout << "this is malloc destructors" << std::endl;
  while (!ptr_set.empty()) {
    auto iter_ptr = ptr_set.begin();
    deallocate<void>(*iter_ptr);
  }
  ptr_set.clear();
}


}  // namespace memory
}  // namespace novamind
