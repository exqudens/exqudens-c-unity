cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
file(READ "${CMAKE_CURRENT_SOURCE_DIR}/name-version.txt" INFO)
string(REPLACE ":" ";" INFO_LIST "${INFO}")
list(GET INFO_LIST 0 RAW_NAME)
list(GET INFO_LIST 1 RAW_VERSION)
string(STRIP "${RAW_NAME}" NAME)
string(STRIP "${RAW_VERSION}" VERSION)
project(exqudens-c-unity C)

#set(CMAKE_C_STANDARD_LIBRARIES "-static-libgcc ${CMAKE_CXX_STANDARD_LIBRARIES}")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
set(CMAKE_C_STANDARD 17)

add_library("${PROJECT_NAME}"
    "src/main/c/chef.h"
    "src/main/c/chef.c"
    "src/main/c/waiter.h"
    "src/main/c/waiter.c"
    "src/main/c/customer.h"
    "src/main/c/customer.c"
)
target_include_directories("${PROJECT_NAME}" PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/main/c>"
    "$<INSTALL_INTERFACE:include>"
)

add_library("test-lib"
    "src/test/c/unity.h"
    "src/test/c/unity.c"
    "src/test/c/unity_internals.h"

    "src/test/c/unity_fixture.h"
    "src/test/c/unity_fixture.c"
    "src/test/c/unity_fixture_internals.h"

    "src/test/c/unity_memory.h"
    "src/test/c/unity_memory.c"

    "src/test/c/test_chef.c"
)
target_include_directories("${PROJECT_NAME}" PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/test/c>"
    "$<INSTALL_INTERFACE:include>"
)
target_link_libraries("test-lib" PUBLIC
    "${PROJECT_NAME}"
)

add_executable("test-app" "src/test/c/main.c")
target_link_libraries("test-app" PUBLIC
    "test-lib"
)
