cmake_minimum_required(VERSION 3.18)
project(spelly)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(spelly src/main.cpp src/word/Word.h src/word/Word.cpp src/math/Matrix.cpp src/math/Matrix.h src/trie/Trie.cpp src/trie/Trie.h src/trie/TrieNode.h src/misc/Utils.cpp src/misc/Utils.h src/correction/Correction.cpp src/correction/Correction.h)
