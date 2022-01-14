cmake_minimum_required(VERSION 3.17)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_sources(${PROJECT_NAME} INTERFACE include/some_header.h include/other_header.h)
target_include_directories(${PROJECT_NAME} INTERFACE include)

if(BUILD_TESTING)
    find_package(doctest REQUIRED)

    add_executable(${PROJECT_NAME}_tests)
    target_sources(${PROJECT_NAME}_tests PRIVATE tests/my_test.cpp)
    target_link_libraries(${PROJECT_NAME}_tests PRIVATE doctest::doctest ${PROJECT_NAME})

    add_test(NAME ${PROJECT_NAME}_tests COMMAND ${PROJECT_NAME}_tests)
endif()
