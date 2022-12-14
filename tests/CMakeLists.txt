cmake_minimum_required(VERSION 3.20)

project(tictactoe_tests
		VERSION 0.1
		DESCRIPTION "Tests for tic-tac-toe game"
		LANGUAGES CXX
)

include(CTest)

find_package(Python COMPONENTS Interpreter REQUIRED)

add_test(NAME test_3x3_PvP
		 COMMAND ${Python_EXECUTABLE} -m pytest ${CMAKE_CURRENT_SOURCE_DIR}/test_3x3_PvP.py
)