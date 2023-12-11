#include "engine.h"
#include "object.h"

constexpr unsigned short SOLID_OBJECT   = 0;
constexpr unsigned short GAS_OBJECT     = 16384;
constexpr unsigned short LIQUID_OBJECT  = 32768;
//constexpr ??? = 49152;

std::map<std::bitset<2>, std::function<void(engine::obj*)>, engine::compareBits<2>> 
engine::callBoxInit {
  std::pair<std::bitset<2>, std::function<void(engine::obj*)>>
    {std::bitset<2>(0), [](engine::obj* self){
      std::cout << "Hello, World!\n---==| I AM SOLID | ==---\n";
    }},
  std::pair<std::bitset<2>, std::function<void(engine::obj*)>>
    {std::bitset<2>(1), [](engine::obj* self){
        std::cout << "\n---==| I AM GAS |==---\n"; 
    }},
};



std::map<std::bitset<16>, std::function<void(engine::obj*)>, engine::compareBits<16>>
engine::callIdInit {
  std::pair<std::bitset<16>, std::function<void(engine::obj*)>>
    {std::bitset<16>(SOLID_OBJECT + 0), [](engine::obj* self){
      std::cout << "\n---==| I AM A WALL |==---\n";
    }},
  std::pair<std::bitset<16>, std::function<void(engine::obj*)>>
    {std::bitset<16>(GAS_OBJECT + 0), [](engine::obj* self) {
      std::cout << "\n---==| I AM AIR |==---\n";
    }},
};
// ТРДЫЕ ОБЪЕКТЫ. ОНИ НЕ РАЗДЕЛЯЮТ СВОЁ ЗДОРОВЬЕ С СОСЕДЯМИ. СОСЕДИ - 4 КЛЕТКИ + ДИАГОНАЛЬНЫЕ, ЕСЛИ ДОСТУПНЫ.
