/*
 * Implementation of Socket class.
 */


#include <cstring>
#include "bsocket.h"

// Constructor and destructor.
Socket::Socket() : socket_fd(-1) {

}

Socket::~Socket() {

}


// Server side.
bool Socket::create() {
    int opt = 1;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == 0) {
        return false;
    }

    return setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) != -1;
}


bool Socket::bind(const uint16_t port) {
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    return ::bind(socket_fd, (struct sockaddr *) &address, sizeof(address)) >= 0;
}

bool Socket::listen() const {
    return ::listen(socket_fd, BACKLOG) >= 0;
}


bool Socket::accept(Socket &newSocket) {
    int addrlen = sizeof(address);
    newSocket.socket_fd = ::accept(socket_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen);
    return newSocket.socket_fd > 0;
}

bool Socket::shutdown(int how) {
    return ::shutdown(socket_fd, how) != -1;
}


// Client side.
bool Socket::connect(const string &host, const uint16_t port) {
    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    inet_pton(AF_INET, host.c_str(), &address.sin_addr);
    if (errno == EAFNOSUPPORT) {
        return false;
    }
    int status = ::connect(socket_fd, (struct sockaddr *) &address, sizeof(address));
    return status == 0;
}


// Shared (data transmission).
bool Socket::send(const string &message) const {
    ssize_t status = ::send(socket_fd, message.c_str(), message.size(), MSG_NOSIGNAL);
    return status != -1;
}


int Socket::recv(string &message) const {
    char buffer[MAXRECVLEN + 1];

    message = "";
    memset(buffer, 0, MAXRECVLEN + 1);
    int status = ::recv(socket_fd, buffer, MAXRECVLEN, 0);
    if (status == -1) {
        cout << "ERRNO: " << errno << "during recv.";
        return -1;
    } else if (status == 0) {
        return 0;
    } else {
        message = buffer;
        return status;
    }
}