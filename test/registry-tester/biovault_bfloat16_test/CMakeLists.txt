cmake_minimum_required(VERSION 3.25)
set(PROJECT_NAME registry-tester-float16)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(biovault_bfloat16 CONFIG REQUIRED)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(myapp PRIVATE biovault_bfloat16::biovault_bfloat16)