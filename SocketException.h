#ifndef _SOCKETEXCEPTION_H
#define _SOCKETEXCEPTION_H

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

#endif //_SOCKETEXCEPTION_H