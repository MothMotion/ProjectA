#ifndef CLIENT_NETWORK_H
#define CLIENT_NETWORK_H

#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class Client {
private:
  int clientSocket;
  struct sockaddr_in serverAddr;
public:
  Client();
  ~Client();

  void connectToServer(const std::string& ip, int port);
  
  std::string receive();
  void send(const std::string& data);
};
#endif
