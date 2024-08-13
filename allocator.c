#include "allocator.h"

allocator_t gpa = {
  .alloc = malloc,
  .free = free,
  .realloc = realloc
};

/* Arena Allocator */

// allocator_t apa = {
//   .alloc = arena_alloc,
//   .free = arena_free,
//   .realloc = arena_realloc
// };

// int main() {
//   // int* arr = apa.alloc(arena, 10 * sizeof(int));
//   // apa.free(arena, arr);
//
//   return 0;
// }
