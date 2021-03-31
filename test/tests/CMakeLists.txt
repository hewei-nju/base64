add_executable(Google_Tests_run AsciiToBase64Test.cpp Base64ToAsciiTest.cpp ../../src/Base64.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)