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

set(CMAKE_CXX_CLANG_TIDY "clang-tidy-12;-checks=-*,google-readability-todo")
set(CMAKE_CXX_CLANG_TIDY "clang-tidy-12;-checks=-*,google-readability-todo;--header-filter=.*")
set(CMAKE_CXX_CLANG_TIDY "clang-tidy-12;-checks=-*,google-readability-todo;--header-filter=.*some.*")

# Something works wrong here!
set(CMAKE_CXX_CLANG_TIDY "clang-tidy-12;-checks=-*,clang-analyzer-cplusplus*,google-readability-todo;--header-filter=.*some.*")

include(CTest)
add_subdirectory(source)
