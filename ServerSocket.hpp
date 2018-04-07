#ifndef FA17_CS425_MP1_SERVERSOCKET_HPP
#define FA17_CS425_MP1_SERVERSOCKET_HPP

#include "socket.hpp"
//#include <zconf.h>

#include <map>

class ServerSocket : public Socket {
public:
    ServerSocket(int domain, int type, int port, int backlog);

private:
    std::map<std::string, int> fileIndex;

    void run();
};

#endif