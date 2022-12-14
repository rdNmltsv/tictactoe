#include <iostream>
#include <stdlib.h>
#include <memory>
#include <limits>
#include "main.h"
#include "tictactoe.h"

int main(int argc, char** argv) {
try {	
	// Main cycle
	for(;;) {
		system("CLS");

		std::cout << "This is TicTacToe game.\n";
		int boardSize;
		GameMode mode;
		bool first_move = true;

		int choise;
		std::cout << "Choose board size (1 - for 3x3; 2 - for 4x4; 3 - for 5x5): ";
		while(std::cin >> choise && (choise < 1 || choise > 3) || std::cin.peek() != '\n') {
			std::cin.clear();
			std::cin.ignore(stream_max_size, '\n');
			std::cout << "Please, make valid choise: ";
		}
		if(choise == 1) boardSize = 3;
		else if(choise == 2) boardSize = 4;
		else boardSize = 5;
		
		std::cout << "Choose game mode (1 - PvE; 2 - PvP; 3 - EvE (demo)): ";
		while(std::cin >> choise && (choise < 1 || choise > 3) || std::cin.peek() != '\n') {
			std::cin.clear();
			std::cin.ignore(stream_max_size, '\n');
			std::cout << "Please, make valid choise: ";
		}
		if(choise == 1) mode = GameMode::PvE;
		else if(choise == 2) mode = GameMode::PvP;
		else mode = GameMode::EvE;
		
		if(mode == GameMode::PvE) {
			std::cout << "Choose who goes first (1 - player; 2 - computer): ";
			while(std::cin >> choise && (choise < 1 || choise > 2) || std::cin.peek() != '\n') {
				std::cin.clear();
				std::cin.ignore(stream_max_size, '\n');
				std::cout << "Please, make valid choise: ";
			}
			if (choise == 1) first_move = true;
			else first_move = false;
		}
		
		auto session = std::make_unique<TicTacToe>(boardSize, mode, first_move); // game session
		session->printBoard();

		for(;;) {
			session->nextTurn();
			session->printBoard();

			if(session->isFinished()) {
				auto result = session->getGameResult();

				if (result == GameStatus::WinX)
					std::cout << "Winner is X!\n";
				else if (result == GameStatus::WinO)
					std::cout << "Winner is O!\n";
				else if (result == GameStatus::Draw)
					std::cout << "Draw!\n";
				else { // GameStatus::InProgress
					throw std::logic_error("Wrong game result.");
				}

				break;
			}
		}
		
		std::cout << "Game finished! Enter 1 to start new game or enter anything else to quit.\n";
		std::cin >> choise;
		if(choise != 1) {
			break;
		}
		else {
			std::cin.clear();
			std::cin.ignore(stream_max_size, '\n');
		}
	}

	return 0;
}
catch(std::exception e) {
	std::cerr << "Exceptrion: " << e.what() << std::endl;
	system("pause");
	return -1;
}	
}