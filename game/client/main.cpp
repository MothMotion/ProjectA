#include "../shared/engine/engine.h"
#include "../shared/engine/object.h"
#include "../shared/engine/vector.h"
#include "../shared/engine/visual.h"
#include "network.h"
#include <vector>



int main() {
  Client client;
  client.connectToServer("127.0.0.1", 8080);

  client.send("Hello from client!");

  std::string receivedData = client.receive();
  std::cout << "Received: " << receivedData << std::endl;
}
