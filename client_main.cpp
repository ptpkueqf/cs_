#include "ClientSocket.h"
#include "SocketException.h"
#include "client.cpp"
#include <iostream>
#include <string>

int main (  )
{
  

      //ClientSocket client_socket ( "127.0.0.1", 10020 );

      std::string reply;

    Client c;
    c.grep();
	  //client_socket << "Test message.";
	  //client_socket >> reply;
	
      

  return 0;
}