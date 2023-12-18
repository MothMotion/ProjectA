#include "network.h"
#include "../shared/engine/engine.h"
#include "../shared/engine/vector.h"
#include "../shared/engine/object.h"

int main() {
  Server server;
  server.start(8080);
  unsigned char actionCode = 74;
  engine::vec<short, char> test_vec(10, 12, 3);
  engine::obj test_obj(std::bitset<2>(0), std::bitset<14>(0));

  std::string test = network::prepareForSend(actionCode, test_vec, test_obj);

  return 0;
}
