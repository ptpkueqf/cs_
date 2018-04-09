#include "ServerSocket.hpp"
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#define MAXSENDLEN 1024

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

        /*if (recv(recvMsg, 0, sockFd))
        {
            string ca(recvMsg);
            cout << "Grep cmd is: " + ca << endl;
        }*/

        system("grep hello test.txt > gput.txt");
        ifstream fin("gput.txt");
        char *buffer1 = new char[1024];

        while (!fin.eof())
        {
            bzero(buffer1, MAXSENDLEN);
            fin.read(buffer1, MAXSENDLEN);
        }

        ifstream finn("gput.txt");
        char *buffer = new char[1024];

        while (!finn.eof())
        {
            bzero(buffer, MAXSENDLEN);
            finn.read(buffer, MAXSENDLEN);
            cout<<"buffer"<<buffer<<endl;
            ::send(sockFd, buffer, MAXSENDLEN, 0);
            cout << "send success";
        }
    }
}
