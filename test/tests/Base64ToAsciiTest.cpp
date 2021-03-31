//
// Created by hewei on 2021/3/31.
//

#include "gtest/gtest.h"
#include "../../src/Base64.h"
#include <fstream>
#include <vector>

// Empty Char / !Base64 chars -> Exception

TEST(Base64, CatchException) {
    const char dot = '.';
    const char mod = '%';
    char ch;
    ASSERT_THROW(Base64().getCharPos(ch), std::runtime_error);
    ASSERT_THROW(Base64().getCharPos(dot), std::runtime_error);
    ASSERT_THROW(Base64().getCharPos(mod), std::runtime_error);
}

TEST(Base64, GetCharPos) {
     static const std::vector<char> base64Chars {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                                 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                                 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                                 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                                 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                                 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                                 'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                                 '4', '5', '6', '7', '8', '9', '+', '/'};
    for (int i = 0; i <= base64Chars.size() - 1; ++i) {
        try {
            int pos = Base64().getCharPos(base64Chars[i]);
            ASSERT_EQ(base64Chars[i], base64Chars[pos]);
        } catch (std::runtime_error &error) {
            std::cerr << error.what() << std::endl;
            ASSERT_TRUE(false);
        }
    }
}

// Base64 -> Ascii
TEST(Base64, Ascii) {
    std::vector<std::string> ascii_file_path{"F:\\Clion\\test\\tests\\ascii-files\\1.txt",
                                             "F:\\Clion\\test\\tests\\ascii-files\\2.txt",
                                             "F:\\Clion\\test\\tests\\ascii-files\\3.txt"};
    std::vector<std::string> base64_file_path{"F:\\Clion\\test\\tests\\base64-files\\1.txt",
                                              "F:\\Clion\\test\\tests\\base64-files\\2.txt",
                                              "F:\\Clion\\test\\tests\\base64-files\\3.txt"};
    for (int i = 0; i <= ascii_file_path.size() - 1; ++i) {
        std::ifstream ascii_infile(ascii_file_path[i]);
        std::ifstream base64_infile(base64_file_path[i]);
        ASSERT_TRUE(ascii_infile.is_open());
        ASSERT_TRUE(base64_infile.is_open());
        std::string ascii_str((std::istreambuf_iterator<char>(ascii_infile)), std::istreambuf_iterator<char>());
        std::string base64_str((std::istreambuf_iterator<char>(base64_infile)), std::istreambuf_iterator<char>());
        ASSERT_EQ(Base64().base64Decode(base64_str), ascii_str);
        ascii_infile.close();
        base64_infile.close();
    }
}

// Base64 -> Zh
TEST(Base64, Zh) {
    std::vector<std::string> zh_file_path{"F:\\Clion\\test\\tests\\zh-files\\1.txt",
                                             "F:\\Clion\\test\\tests\\zh-files\\2.txt",
                                             "F:\\Clion\\test\\tests\\zh-files\\3.txt"};
    std::vector<std::string> base64_file_path{"F:\\Clion\\test\\tests\\base64-files\\4.txt",
                                              "F:\\Clion\\test\\tests\\base64-files\\5.txt",
                                              "F:\\Clion\\test\\tests\\base64-files\\6.txt"};
    for (int i = 0; i <= zh_file_path.size() - 1; ++i) {
        std::ifstream zh_infile(zh_file_path[i]);
        std::ifstream base64_infile(base64_file_path[i]);
        ASSERT_TRUE(zh_infile.is_open());
        ASSERT_TRUE(base64_infile.is_open());
        std::string zh_str((std::istreambuf_iterator<char>(zh_infile)), std::istreambuf_iterator<char>());
        std::string base64_str((std::istreambuf_iterator<char>(base64_infile)), std::istreambuf_iterator<char>());
        ASSERT_EQ(Base64().base64Decode(base64_str), zh_str);
        zh_infile.close();
        base64_infile.close();
    }
}


