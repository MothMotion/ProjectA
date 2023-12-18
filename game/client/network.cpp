#include "network.h"

Client::Client() {
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if(clientSocket == -1) {
    std::cerr << "Error creating socket\n";
    exit(EXIT_FAILURE);
  }
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = 0;
}

Client::~Client() {
  close(clientSocket);
}

void Client::connectToServer(const std::string& ip, int port) {
  serverAddr.sin_port = htons(port);

  if(inet_pton(AF_INET, ip.c_str(), &serverAddr.sin_addr) == -1) {
    std::cerr << "Invalid address/Address not supported\n";
    exit(EXIT_FAILURE);
  }

  if(connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
    std::cerr << "Connection failed\n";
    exit(EXIT_FAILURE);
  }
}

std::string Client::receive() {
  char buffer[1024] = {0};
  ssize_t valread = read(clientSocket, buffer, sizeof(buffer));
  if(valread == -1) {
    std::cerr << "Error reading from socket\n";
    exit(EXIT_FAILURE);
  }
  return std::string(buffer);
}

void Client::send(const std::string& data) {
  ::send(clientSocket, data.c_str(), data.size(), 0);
}
