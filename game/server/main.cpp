#include "network.h"
#include "../shared/engine/engine.h"
#include "../shared/engine/vector.h"
#include "../shared/engine/object.h"

int main() {
  Server server;
  server.start(8080);

  return 0;
}
