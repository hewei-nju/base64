//
// Created by hewei on 2021/3/28.
//

#include "Base64.h"
#include <stdexcept>



constexpr static const char base64Chars[64] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                               'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                               'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                               'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                               'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                               'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                               'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                               '4', '5', '6', '7', '8', '9', '+', '/'};

Base64::Base64() {};

unsigned short Base64::getCharPos(const char &ch) {
    if (&ch == nullptr) throw std::runtime_error("Input char is null!");
    if (ch >= 'A' && ch <= 'Z') return ch - 'A';
    else if (ch >= 'a' && ch <= 'z') return ch - 'a' + 'Z' - 'A' + 1;
    else if (ch >= '0' && ch <= '9') return ch - '0' + 'Z' - 'A' + 'z' - 'a' + 2;
    else if (ch == '+') return 62;
    else if (ch == '/') return 63;
    else throw std::runtime_error("Input char is not valid Base64 code!");
}

std::string Base64::base64Encode(const std::string &s) {
    if (s.empty()) throw std::runtime_error("Input string is null!");
    std::string ret;
    unsigned int pos = 0;
    int strLen = s.size();
    while (pos <= strLen - 1) {
        if (pos % 3 == 0) {
            ret.push_back(base64Chars[(0x00FC & s[pos]) >> 2]);
        } else if (pos % 3 == 1) {
            ret.push_back(base64Chars[((0x0003 & s[pos - 1]) << 4) + ((0x00F0 & s[pos]) >> 4)]);
        } else {
            ret.push_back(base64Chars[((0x000F & s[pos - 1]) << 2) + ((0x00C0 & s[pos]) >> 6)]);
            ret.push_back(base64Chars[0x003F & s[pos]]);
        }
        ++pos;
    }

    if (pos % 3 == 1) {
        ret.push_back(base64Chars[(0x0003 & s[pos - 1]) << 4]);
        ret.push_back('=');
        ret.push_back('=');
    } else if (pos % 3 == 2) {
        ret.push_back(base64Chars[(0x000F & s[pos - 1]) << 2]);
        ret.push_back('=');
    }
    return ret;
}


std::string Base64::base64Decode(const std::string &s) {
    if (&s == nullptr) throw std::runtime_error("Input string is null!");
    std::string ret;
    unsigned int pos = 0;
    int strLen = s.size();
    while (pos <= strLen - 1) {
        try {
            unsigned int charPos = getCharPos(s[pos]);
            if (pos % 4 == 0) {  // 为什么 pos & 0x0003不行呢？
                try {
                    unsigned int nextCharPos = getCharPos(s[pos + 1]);
                    char ch = char(((charPos & 0x003F) << 2) + ((nextCharPos & 0x0030) >> 4));
                    ret.push_back(ch);
                } catch (std::runtime_error error) {
                    throw error;
                }
            } else if (pos % 4 == 1) {
                if (s[pos + 1] == '=') {
                    break;
                } else {
                    try {
                        unsigned int nextCharPos = getCharPos(s[pos + 1]);
                        char ch = char(((charPos & 0x000F) << 4) + ((nextCharPos & 0x003C) >> 2));
                        ret.push_back(ch);
                    } catch (std::runtime_error error) {
                        throw error;
                    }
                }
            } else if (pos % 4 == 2) {
                if (s[pos + 1] == '=') {
                    break;
                } else {
                    try {
                        unsigned int nextCharPos = getCharPos(s[pos + 1]);
                        char ch = char(((charPos & 0x0003) << 6) + (nextCharPos & 0x003F));
                        ret.push_back(ch);
                        ++pos;
                    } catch (std::runtime_error error) {
                        throw error;
                    }
                }
            }
            ++pos;
        } catch (std::runtime_error error) {
            throw error;
        }
    }
    return ret;
}