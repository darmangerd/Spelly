cmake_minimum_required(VERSION 3.18)
project(spelly)

set(CMAKE_CXX_STANDARD 20)
find_package(Threads REQUIRED)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/f079775276a99fd4373569bf5761052a01844270.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datas/french.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datas/french_test.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datas/test.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Spelly app
add_executable(
        spelly
        src/main.cpp
        src/word/Word.h
        src/word/Word.cpp
        src/math/Matrix.cpp
        src/math/Matrix.h
        src/trie/Trie.cpp
        src/trie/Trie.h
        src/trie/TrieNode.h
        src/misc/Utils.cpp
        src/misc/Utils.h
        src/correction/Correction.cpp
        src/correction/Correction.h
        src/gui/Interaction.cpp
        src/gui/Interaction.h
)
target_link_libraries(
        spelly
        Threads::Threads
)

# Tests
add_executable(
        spelly_tests
        src/word/Word.h
        src/word/Word.cpp
        src/math/Matrix.cpp
        src/math/Matrix.h
        src/trie/Trie.cpp
        src/trie/Trie.h
        src/trie/TrieNode.h
        src/misc/Utils.cpp
        src/misc/Utils.h
        src/correction/Correction.cpp
        src/correction/Correction.h
        tests/WordTest.cpp
        tests/SpellingTest.cpp
        tests/MatrixTest.cpp
        tests/UtilsTest.cpp
)
target_link_libraries(
        spelly_tests
        gtest_main
        Threads::Threads
)
