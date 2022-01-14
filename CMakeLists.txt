cmake_minimum_required(VERSION 3.17)
project(test_clang_tidy)

set(CMAKE_CXX_STANDARD 20)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(conan)
conan_cmake_run(
    REQUIRES doctest/2.4.6
    GENERATORS cmake_find_package
    BUILD missing
)
# clang-analyzer-cplusplus*
option(TEST_NO_HEADERS "Without --header-filter" ON)
option(TEST_ALL_HEADERS "--header-filter=.*" OFF)
option(TEST_SOME_HEADERS "--header-filter=.*some.*" OFF)

if (TEST_NO_HEADERS)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy-12;-checks=-*,clang-analyzer-cplusplus*,google-readability-todo")
endif()
if (TEST_ALL_HEADERS)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy-12;-checks=-*,clang-analyzer-cplusplus*,google-readability-todo;--header-filter=.*")
endif()
if (TEST_SOME_HEADERS)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy-12;-checks=-*,clang-analyzer-cplusplus*,google-readability-todo;--header-filter=.*some.*")
endif()

include(CTest)
add_subdirectory(source)
