cmake_minimum_required(VERSION 3.14)
project(reverse_words LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(reverse_words
    src/main.cpp
    src/reverse_words.cpp
)

add_executable(test_reverse_words
    test/test_reverse_words.cpp
    src/reverse_words.cpp
)

enable_testing()
add_test(NAME reverse_words_test COMMAND test_reverse_words)
