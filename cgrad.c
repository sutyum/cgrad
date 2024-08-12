#include <stdio.h>

typedef struct {
  float data;
  float _prev_data;
} value_t;

void value_print(value_t v) {
  printf("Value(data=%0.4f)\n", v.data);
}

value_t value_create(float data) {
  return (value_t){ 
    .data = data
  };
}

value_t value_add(value_t a, value_t b) {
  return (value_t){ 
    .data = a.data + b.data
  };
}

value_t value_mul(value_t a, value_t b) {
  return (value_t){ 
    .data = a.data * b.data
  };
}

int main() {
  value_t a = value_create(3.0);
  value_t b = value_create(-4.0);

  value_t c = value_add(a, b);
  value_print(c);

  value_t d = value_mul(a, b);
  value_print(d);

  return 0;
}
