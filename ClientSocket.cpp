#include <fstream>
#include "ClientSocket.h"
#include "SocketException.h"

ClientSocket::ClientSocket(string host, int port) {
    if (!Socket::create()) {
        throw SocketException("Create basesocket failed.");
    }
    if (!Socket::connect(host, (uint16_t) port)) {
        throw SocketException("Connect to designated host & port failed.");
    }
}


void ClientSocket::receiveMessage(ofstream &fout) {
    string buffer;
    int status;
    while ((status = Socket::recv(buffer)) > 0) {
//        cout << "Received: " << buffer << endl;
        fout << buffer;
    }
    if (status == -1) {
        throw SocketException("Receive from basesocket failed.");
    }
    if (!Socket::send("Recv Finished.")) {
        throw SocketException("Send to basesocket failed.");
    }
}


const ClientSocket &ClientSocket::operator<<(const string &message) const {
    if (!Socket::send(message)) {
        throw SocketException("Write to basesocket failed.");
    }
    return *this;
}


const ClientSocket &ClientSocket::operator>>(string &message) const {
    if (Socket::recv(message) == 0) {
        throw SocketException("Read from basesocket failed.");
    }
    return *this;
}