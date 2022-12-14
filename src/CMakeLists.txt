cmake_minimum_required(VERSION 3.20)

project(tictactoe
		VERSION 0.1
		DESCRIPTION "Tic-tac-toe game"
		LANGUAGES CXX
)

file(GLOB SOURCES *.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)