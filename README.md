# Description
Yet another tic-tac-toe implementation on C++.

# How to build
1. git clone or download source code from this repo.
2. run CMake GUI (or [download](https://cmake.org/download/) at least version 3.20.0. if dont have one).
3. select directory, containing CMakeLists.txt.
4. select directory, where CMake should build binaries - consider create a folder **build/** near CMakeLists.txt.
5. click *Configure* to start project configurating.
6. when asked, specify generator you want to use - originally used generator was MS Visual Studio 2019.
7. also recommended to specify C++ compiler you want to use for compiling by select *Specify native compilers*.
8. after configuring done, click *Generate* to generate specific generator files which you chose on step 6.
9. at the last step you want to build binaries - you can use chosen generator, or you can do this using command line: just type in *cmake --build .* while you're in build/ directory
10. after building done you'll find executable *tictactoe.exe* in *build-folder/*.

# How to test
1. run CTest from project folder: ctest -C Debug -VV (-C <config> <- for generator with configs, -VV for verbose output).

# How to use
1. run executable from *build-folder/*.
2. select board size.
3. select game mode.
4. if playing vs computer you can choose who goes first.
5. enter number of corresponding empty cell on board to make move.
6. player who succeeds in placing 3/4/5 of their marks in a horizontal, vertical, or diagonal row is the winner.
