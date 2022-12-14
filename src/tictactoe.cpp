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
	int move = minimax(_board, is_maximizing, 0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()).second;
	if (!_board.makeMove(move))
		throw std::logic_error("AI impossible move.");
}

// minimax algorithm
std::pair<int, int> TicTacToe::minimax(Board board, bool is_maximizing, int depth, int alpha, int beta) {
	if (board.isFinished()) {
		auto result = board.getGameStatus();

		if (result == GameStatus::WinX)
			return { 1000, -1 };
		else if (result == GameStatus::WinO)
			return { -1000, -1 };
		else if (result == GameStatus::Draw)
			return { 0, -1 };
		else { // GameStatus::InProgress
			throw std::logic_error("Wrong game result.");
		}
	}

	int best_move = -1;
	int best_value = is_maximizing ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();

	auto moves = board.findAvailableMoves();

	// optimize finding first move
	if (moves.size() == board.getSize() || moves.empty()) {
		// make random move
		std::random_device rd;
		std::mt19937 engine(rd());
		std::uniform_int_distribution ud(0, board.getSize() - 1);
		return { 0, ud(engine) };
	}

	for (auto move : moves) {
		// limit calculation depth
		if (depth > 5) {
			return { 0, -1 };
		}

		auto new_board = board;
		if(!new_board.makeMove(move))
			throw std::logic_error("AI impossible move.");

		int possible_value;

		if (auto it = _cache.find(new_board.getPosition()); it != _cache.end()) {
			possible_value = it->second;
		}
		else {
			possible_value = minimax(new_board, !is_maximizing, depth + 1, alpha, beta).first;
			_cache.insert(std::make_pair(new_board.getPosition(), possible_value));
		}
		
		if (is_maximizing && possible_value > best_value) {
			best_value = possible_value - depth * 10;
			best_move = move;
			alpha = std::max(alpha, best_value);
			if (beta <= alpha)
				break;
		}
		else if (!is_maximizing && possible_value < best_value) {
			best_value = possible_value + depth * 10;
			best_move = move;
			beta = std::min(beta, best_value);
			if (beta <= alpha)
				break;
		}
	}

	return std::make_pair(best_value, best_move);
}