cmake_minimum_required(VERSION 3.20)

if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

project(tictactoe)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)