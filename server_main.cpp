#include <pthread.h>
#include<fstream>

#include "ServerSocket.hpp"

int main() {
    ServerSocket server(AF_INET, SOCK_STREAM, 10020, 10);

   
}