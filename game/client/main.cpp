#include "engine/engine.h"
#include "engine/object.h"
#include "engine/vector.h"



int main() {
  std::bitset<2> test_box(0);
  std::bitset<14> test_id(0);
  engine::obj test_object(std::bitset<2>(1), std::bitset<14>(0));
  return 0;
}
