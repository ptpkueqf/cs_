#ifndef FA17_CS425_MP1_CONFIGEXCEPTION_H
#define FA17_CS425_MP1_CONFIGEXCEPTION_H

#include <string>

using namespace std;

class ConfigException : public exception {
public:
    explicit ConfigException(const char *s) : message(s) {

    }

    string getMessage() {
        return message;
    }

private:
    string message;
};

#endif //FA17_CS425_MP1_CONFIGEXCEPTION_H