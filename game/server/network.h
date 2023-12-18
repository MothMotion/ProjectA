#ifndef SERVER_NETWORK_H
#define SERVER_NETWORK_H
#pragma once

#include "../shared/engine/engine.h"
#include "../shared/engine/vector.h"
#include "../shared/engine/object.h"

#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class Server {
private:
  int serverSocket;
  int clientSocket;
  struct sockaddr_in serverAddr;
  struct sockaddr_in clientAddr;
public:
  Server();
  ~Server();

  void start(int port);

  std::string receive();
  void send(const std::string& data);
};

// ШИФРОВАНИЕ СЕТИ:

constexpr unsigned short BOX_OFFSET = 16384;

namespace network {
  template<typename anyType>
  std::string toBinary(const anyType& integer);

  std::string objCode(const engine::obj& object);/* {
    std::string objectCode = toBinary(object.getBox()[0]*2*BOX_OFFSET + object.getBox()[1]*BOX_OFFSET + (unsigned short)object.getID().to_ulong()) + toBinary(object.getHealth());
    return objectCode;
  }*/
  template<typename anyType0, typename anyType1>
  std::string vecCode(const engine::vec<anyType0, anyType1>& vector);/* {
    std::string vectorCode = toBinary(vector.getX()) + toBinary(vector.getY()) + toBinary(vector.getZ());
    return vectorCode;
  }*/
  
  template<typename anyType0, typename anyType1>
  std::string dataCode(const engine::vec<anyType0, anyType1>& position, const engine::obj& object);/* {
    return vecCode(position) + objCode(object);
  }*/
  template<typename anyType0, typename anyType1>
  std::string prepareForSend(unsigned char& actionCode, engine::vec<anyType0, anyType1>& position, engine::obj& object);/* {
    std::string readyToSend;
    readyToSend.push_back(actionCode);
    return readyToSend + dataCode(position, object);
  }*/
};

#endif
