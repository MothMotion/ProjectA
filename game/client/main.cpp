#include "engine/engine.h"



int main() {
  std::bitset<4> test_box(0);
  std::bitset<12> test_id(1);
  engine::obj test_obj(test_box, test_id);
  return 0;
}
