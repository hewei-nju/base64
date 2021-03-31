//
// Created by hewei on 2021/3/31.
//

#include "gtest/gtest.h"
#include "../../src/Base64.h"
#include <fstream>
#include <vector>

// Empty String -> Exception
TEST(EmptyAscii, Exception) {
    std::string str;
    ASSERT_THROW(Base64().base64Encode(str), std::runtime_error);
}

// Ascii -> Base64
TEST(Ascii, Base64) {
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
        ASSERT_EQ(Base64().base64Encode(ascii_str), base64_str);
        ascii_infile.close();
        base64_infile.close();
    }
}

// Zh -> Ascii
TEST(Zh, Ascii) {
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
        ASSERT_EQ(Base64().base64Encode(zh_str), base64_str);
        zh_infile.close();
        base64_infile.close();
    }
}



