cmake_minimum_required(VERSION 3.25)
set(PROJECT_NAME registry-tester-hdilib)
project(${PROJECT_NAME})
set(VCPKG_BUILD_TYPE release)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(lz4 CONFIG REQUIRED)
find_package(flann CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(kompute CONFIG REQUIRED)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

find_package(OpenMP)
find_package(HDILib COMPONENTS hdidimensionalityreduction hdiutils hdidata CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE 
  ${HDILib_LINK_LIBS}
  OpenGL::GL)
target_include_directories(${PROJECT_NAME} PRIVATE ${HDILib_INCLUDE_DIR})
# Force the test executable to use the Dynamic CRT (/MD or /MDd) to match vcpkg
set_target_properties(${PROJECT_NAME} PROPERTIES
    MSVC_RUNTIME_LIBRARY "MultiThreadedDLL"
)
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/utf-8>)