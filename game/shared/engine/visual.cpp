#include "engine.h"
#include "visual.h"
#include "vector.h"
#include "object.h"

constexpr unsigned short DEBUG_SIZE = 16;

namespace interface {

void debug(std::vector<engine::obj*> objects) {
  std::cout << "\n/======DEBUG  OBJECTS======\\\n";
  for(unsigned short i=0; i<std::min(DEBUG_SIZE, (unsigned short)objects.size()); ++i) {
    std::cout << "| BOX:" << objects.at(i)->getBox()
      << " ID:" << objects.at(i)->getID() << " |\n";
  }
  for(unsigned short i=0; i<std::max(0, DEBUG_SIZE-(unsigned short)objects.size()); ++i) {
    std::cout << "|                          |\n";
  }
  std::cout << "\\==========================/"; 
  for(unsigned short i=0; i<DEBUG_SIZE+2; ++i) std::cout << "\x1b[A\r";
  std::cout << std::flush;
}
}
