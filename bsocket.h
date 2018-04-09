/*
 * Encapsulation of Socket.
 * Refer to http://tldp.org/LDP/LG/issue74/tougher.html.
 */
#ifndef nn_dgrep
#define nn_dgrep

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;
#define BACKLOG 3 // maximum length to which the queue of pending connections may grow.
#define MAXRECVLEN 1024


class Socket {
public:
    Socket();

    virtual ~Socket();

    // Server side.
    bool create();

    bool bind(const uint16_t port);

    bool listen() const;

    bool accept(Socket &newSocket);

    bool shutdown(int how);

    // Client side.
    bool connect(const string &host, const uint16_t port);

    // Shared (data transmission).
    bool send(const string &message) const;

    int recv(string &message) const;

    bool recvv(void *buf, unsigned int flags);

private:
    int socket_fd; // basesocket file descriptor.
    struct sockaddr_in address;
};


#endif 