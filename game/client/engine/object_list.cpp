#include "engine.h"
#include "object.h"
//#include "object.cpp"


std::map<std::bitset<2>, std::function<void(engine::obj*)>, engine::compareBits<2>> 
engine::callBoxInit = {
  {std::bitset<2>(0), [](engine::obj* ptr){std::cout << "Hello, World!";}}
};
// ТРДЫЕ ОБЪЕКТЫ. ОНИ НЕ РАЗДЕЛЯЮТ СВОЁ ЗДОРОВЬЕ С СОСЕДЯМИ. СОСЕДИ - 4 КЛЕТКИ + ДИАГОНАЛЬНЫЕ, ЕСЛИ ДОСТУПНЫ.
