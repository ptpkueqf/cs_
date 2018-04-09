#ifndef _SOCKET_HPP
#define _SOCKET_HPP

#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>

#define MAXRECVLEN 1024


class Socket {
private:
    int socketFD_;
    struct sockaddr_in serverAddress_, clientAddress_;

public:
    Socket(int domain, int type, int port, int backlog);

    bool bind();

    bool listen(int backlog);

    int accept();

    bool connect(struct sockaddr *serverAddr, socklen_t size);

    bool recv(void *buf, unsigned int flags, int socketFd);

    bool send(const void *msg, int len, int flags);

    //void *getClientIp(char *clientIP);

    bool close();

    bool close(int socketFd);
};

#endif //_SOCKET_HPP