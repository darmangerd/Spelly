cmake_minimum_required(VERSION 3.18)
project(spelly)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/f079775276a99fd4373569bf5761052a01844270.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

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
)

add_executable(
        tests_run
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
        tests/UtilsTest.cpp)

# Now simply link against gtest or gtest_main as needed. Eg
target_link_libraries(tests_run gtest_main)
