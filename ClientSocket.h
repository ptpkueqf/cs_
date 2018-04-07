#ifndef FA17_CS425_MP1_CLIENTSOCKET_H
#define FA17_CS425_MP1_CLIENTSOCKET_H


#include "bsocket.h"

class ClientSocket : public Socket {
public:
    ClientSocket(string host, int port);

    // Keep read until receive FIN package.
    void receiveMessage(ofstream &fout);

    const ClientSocket &operator<<(const string &message) const;

    const ClientSocket &operator>>(string &message) const;
};


#endif