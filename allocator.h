#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stdlib.h>

typedef struct allocator_t {
  void* (*alloc)(size_t size);
  void (*free)(void* ptr);
  void* (*realloc)(void* ptr, size_t size);
} allocator_t;

/* Arena allocator */
typedef struct arena_t {
  size_t size;
  size_t used;
  void* ptr;
} arena_t;

#endif // ALLOCATOR_H
