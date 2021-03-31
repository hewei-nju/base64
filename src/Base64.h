//
// Created by hewei on 2021/3/28.
//

#ifndef CLION_BASE64_H
#define CLION_BASE64_H

#include <string>

class Base64 {
public:
    Base64();
    static unsigned short getCharPos(const char &ch);
    static std::string base64Encode(std::string const &s);
    static std::string base64Decode(std::string const &s);
};


#endif //CLION_BASE64_H
