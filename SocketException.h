#ifndef FA17_CS425_MP1_SOCKETEXCEPTION_H
#define FA17_CS425_MP1_SOCKETEXCEPTION_H

#include <string>

using namespace std;

class SocketException : public exception {
public:
    explicit SocketException(const char *s) : message(s) {

    }

    string getMessage() {
        return message;
    }

private:
    string message;
};

#endif //FA17_CS425_MP1_SOCKETEXCEPTION_H