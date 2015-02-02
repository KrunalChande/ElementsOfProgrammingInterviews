project(ctci-c++)
cmake_minimum_required(VERSION 2.6)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -I -D -fPIC")
SET(CMAKE_VERBOSE_MAKEFILE ON)
message("cmake source dir: " ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Doxygen)
if(DOXYGEN_FOUND)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
add_custom_target(doc
${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../src
COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)

include_directories (
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_BINARY_DIR}
)
add_library(CppUnitLiteCppFiles CppUnitLite/Test.cpp CppUnitLite/TestRegistry.cpp CppUnitLite/TestResult.cpp)
add_subdirectory(src)

