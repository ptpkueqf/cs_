#include "ServerSocket.hpp"
#include <unistd.h>
#include <iostream>
#include <string.h>
using namespace std;

ServerSocket::ServerSocket(int domain, int type, int port, int backlog)
    : Socket(domain, type, port, backlog)
{
    cout << "server start running" << endl;
    run();
}

void ServerSocket::run()
{
    int sockFd;
    cout << "wait for connection" << endl;
    while (true)
    {

        if ((sockFd = accept()) != -1)
        {
            cout << "Receive connection" << endl;
        }
        char recvMsg[1024];
        bzero(recvMsg, 1024);

        if (recv(recvMsg, 0, sockFd))
        {
            string ca(recvMsg);
            cout << "cmd is " + ca << endl;
        }
    }
}
