# Makefile for the socket programming example
#
#CFLAGS=-Wall -g
#LDFLAGS=-pthread
simple_server_objects = ServerSocket.o socket.o server_main.o
simple_client_objects = ClientSocket.o client.o bsocket.o  client_main.o
CXX     = g++
DEBUG   = -g
CXXFLAGS  = -Wall $(DEBUG) -std=c++11 -pthread
LDFLAGS = -lpthread

all : simple_server simple_client

simple_server: $(simple_server_objects)
	g++ -o simple_server $(simple_server_objects) 
	

simple_client: $(simple_client_objects)
	#g++ -o simple_client $(simple_client_objects) 
	$(CXX)  -o $@ $^ $(LIBS) $(LDFLAGS)


socket: socket.cpp
client: client.cpp
bsocket: bsocket.cpp
ServerSocket: ServerSocket.cpp
ClientSocket: ClientSocket.cpp
simple_server_main: simple_server_main.cpp
simple_client_main: simple_client_main.cpp


clean:
	rm -f *.o simple_server simple_client
