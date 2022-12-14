cmake_minimum_required(VERSION 3.20)

project(tictactoe_tests
		VERSION 0.1
		DESCRIPTION "Tests for tic-tac-toe game"
		LANGUAGES CXX
)

include(CTest)

find_package(Python COMPONENTS Interpreter REQUIRED)

#
#include(FetchContent)
#
#FetchContent_Declare(
#	googletest
#	GIT_REPOSITORY 	https://github.com/google/googletest.git
#	GIT_TAG			release-1.12.1
#)
#FetchContent_MakeAvailable(googletest)
#add_library(GTest::GTest INTERFACE IMPORTED)
#target_link_libraries(GTest::GTest INTERFACE gtest_main)

#add_executable(${PROJECT_NAME} tests.cpp)
#target_link_libraries(${PROJECT_NAME} PRIVATE GTest::GTest)
#target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
#add_test(tictactoe_tests tictactoe_tests)

add_test(NAME test_3x3_PvP
		 COMMAND ${Python_EXECUTABLE} -m pytest ${CMAKE_CURRENT_SOURCE_DIR}/test_3x3_PvP.py
)