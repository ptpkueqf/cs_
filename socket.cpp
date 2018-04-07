#include <arpa/inet.h>
#include <memory.h>
#include <unistd.h>
#include<stdio.h>
#include "socket.hpp"
using namespace std;

Socket::Socket(int domain, int type, int port, int backlog) {
    if ((socketFD_ = socket(domain, type, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    bzero((char *) &serverAddress_, sizeof(serverAddress_));
    serverAddress_.sin_family = domain;
    serverAddress_.sin_port = htons(port);
    serverAddress_.sin_addr.s_addr = INADDR_ANY;

    bind();
    listen(backlog);
}

bool Socket::bind() {
    if (::bind(socketFD_, (struct sockaddr *) &serverAddress_, sizeof(serverAddress_)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    return true;
}

bool Socket::listen(int backlog) {
    if (::listen(socketFD_, backlog) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    return true;
}

int Socket::accept() {
    int ret_socket;
    socklen_t addrLen = sizeof(clientAddress_);
    if ((ret_socket = ::accept(socketFD_, (struct sockaddr *) &clientAddress_, &addrLen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return ret_socket;
}

bool Socket::connect(struct sockaddr *serverAddr, socklen_t size) {
    if (::connect(socketFD_, serverAddr, size) < 0) {
        printf("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }
    return true;
}

bool Socket::recv(void *buf, unsigned int flags, int socketFd) {
    int totalBytesRead = 0;
    int bytesRead = 0;
    do {
        bytesRead = ::recv(socketFd, buf, MAXRECVLEN + 1, flags);
        std::cout << "read " + std::to_string(bytesRead) + " bytes" << std::endl;
        if (bytesRead < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        totalBytesRead += bytesRead;
    } while (bytesRead >= (MAXRECVLEN + 1));

    return true;
}

bool Socket::send(const void *msg, int len, int flags) {
    if (::send(socketFD_, msg, len, flags) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    return true;
}

/*void *Socket::getClientIp(char *clientIP) {
    inet_ntop(AF_INET, &(clientAddress_.sin_addr), clientIP, INET_ADDRSTRLEN);
}*/

bool Socket::close() {
    if (::close(socketFD_) != 0) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    return true;
}

bool Socket::close(int socketFd) {
    if (::close(socketFd) != 0) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    return true;
}