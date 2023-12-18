#include "network.h"

Server::Server() {
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if(serverSocket == -1) {
    std::cerr << "Error creating socket\n";
    exit(EXIT_FAILURE);
  }
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddr.sin_port = 8080;
}

void Server::start(int port) {
  serverAddr.sin_port = htons(port);

  if(bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
    std::cerr << "Binding failed.\n";
    exit(EXIT_FAILURE);
  }
  if(listen(serverSocket, 1) == -1) {
    std::cerr << "Listening failed.\n";
    exit(EXIT_FAILURE);
  }

  socklen_t clientLen = sizeof(clientAddr);
  clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientLen);
  if(clientSocket == -1) {
    std::cerr << "Accept failed\n";
    exit(EXIT_FAILURE);
  }
}

std::string Server::receive() {
  char buffer[1024] = {0};
  ssize_t valread = read(clientSocket, buffer, sizeof(buffer));
  if(valread == -1) {
    std::cerr << "Error reading from socket.\n";
    exit(EXIT_FAILURE);
  }
  return std::string(buffer);
}

void Server::send(const std::string& data) {
  ::send(clientSocket, data.c_str(), data.size(), 0);
}

Server::~Server() {
  close(clientSocket);
  close(serverSocket);
} 

// МЕТОДЫ ШИФРОВАНИЯ И КОДИРОВКИ СЕТИ

//constexpr unsigned short BOX_OFFSET = 16384;

namespace network {
  template<typename anyType>
  std::string toBinary(const anyType& value) {
    std::string binaryString;
    const unsigned short bitLen = sizeof(value);
    unsigned char byte;

    for(short i = bitLen-1; i >= 0; --i) {
      byte = (value >> (i*8)) & 0xFF;
      binaryString += byte;
    }

    return binaryString;
  }

  std::string objCode(const engine::obj& object) {
    std::bitset<2> boxFix = object.getBox();
    std::bitset<14> idFix = object.getID();
    std::string objectCode = toBinary((unsigned short)engine::connectBits(boxFix, idFix).to_ulong()) + toBinary(object.getHealth());
    return objectCode;
  }
  //template<typename anyType0, typename anyType1>
  std::string vecCode(const engine::vec<short, char>& vector) {
    std::string vectorCode = toBinary(vector.getX()) + toBinary(vector.getY()) + toBinary(vector.getZ());
    return vectorCode;
  }
  
  //template<typename anyType0, typename anyType1>
  std::string dataCode(const engine::vec<short, char>& position, const engine::obj& object) {
    return vecCode(position) + objCode(object);
  }
  //template<typename anyType0, typename anyType1>
  std::string prepareForSend(unsigned char& actionCode, engine::vec<short, char>& position, engine::obj& object) {
    std::string readyToSend; readyToSend.push_back(actionCode);
    readyToSend += dataCode(position, object);
    for(unsigned char ch : readyToSend) std::cout << (int)ch << " ";
    return readyToSend;
  }
  //template<typename short, typename char>
  //std::string prepareForSend<short, char>(unsigned char& actionCode, engine::vec<short, char>& position, engine::obj& object);
}
