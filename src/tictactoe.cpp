#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <limits>
#include <algorithm>
#include <random>
#include "main.h"
#include "tictactoe.h"

void TicTacToe::printBoard() {
	_board.print();
}

void TicTacToe::nextTurn() {
	auto turn = _board.getTurn();
	std::cout << "Turn: " << (turn == Turn::X ? "X" : "O") << '\n';
	if(_mode == GameMode::PvE) {
		if(turn == Turn::X) {
			if(_first_move)
				playerTurn();
			else
				aiTurn();
		}
		else {
			if (_first_move)
				aiTurn();
			else
				playerTurn();
		}
	}
	else if(_mode == GameMode::PvP) {
		playerTurn();
	}
	else { // _mode == GameMode::EvE
		aiTurn();
	}
}

void TicTacToe::playerTurn() {
	int move;
	do {
		std::cin.clear();
		std::cin.ignore(stream_max_size, '\n');
		std::cout << "Enter number of empty cell: ";
	} while (!(std::cin >> move) || std::cin.peek() != '\n' || !_board.makeMove(--move));
}

void TicTacToe::aiTurn() {
	auto turn = _board.getTurn();
	bool is_maximizing = turn == Turn::X ? true : false;
	int move = minimax(_board, is_maximizing, 0).second;
	if (!_board.makeMove(move))
		throw std::logic_error("AI impossible move.");
}

// minimax algorithm
std::pair<int, int> TicTacToe::minimax(Board board, bool is_maximizing, int depth) {
	if (board.isFinished()) {
		auto result = board.getGameStatus();

		if (result == GameStatus::WinX)
			return { 100 - depth, -1 };
		else if (result == GameStatus::WinO)
			return { depth - 100, -1 };
		else if (result == GameStatus::Draw)
			return { 0, -1 };
		else { // GameStatus::InProgress
			throw std::logic_error("Wrong game result.");
		}
	}

	int best_move = -1;
	int best_value = is_maximizing ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();

	auto moves = board.findAvailableMoves();
	
	//std::random_device rd;
	//std::mt19937 g(rd());
	//std::shuffle(moves.begin(), moves.end(), g);

	for (auto move : moves) {
		auto new_board = board;
		if(!new_board.makeMove(move))
			throw std::logic_error("AI impossible move.");

		auto possible_value = minimax(std::move(new_board), !is_maximizing, depth + 1).first;
		if (is_maximizing && possible_value > best_value || !is_maximizing && possible_value < best_value) {
			best_value = possible_value;
			best_move = move;
		}
	}

	return std::make_pair(best_value, best_move);
}