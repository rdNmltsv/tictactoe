#include <iostream>
#include <iomanip>
#include "board.h"


void Board::print() {
	system("CLS");

	for (int i = _boardSize - 1; i >= 0; --i) {
		for (int j = 0; j < _boardSize; ++j) {
			auto cell = _board.at(i).at(j);
			
			if (cell == CellStatus::Empty) {
				std::cout << std::setw(3) << (_boardSize * i + j + 1);
			}
			else if (cell == CellStatus::X) {
				std::cout << std::setw(3) << 'X';
			}
			else { // if (cell == CellStatus::O)
				std::cout << std::setw(3) << 'O';
			}
		}
		std::cout << "\n\n";
	}
}

void Board::evaluate(int move)
{
	int col = move % _boardSize;
	int row = move / _boardSize;
	auto sym = _turn == Turn::X ? CellStatus::X : CellStatus::O; 

	bool win_row = true;
	for (const auto& cell : _board.at(row)) {
		win_row &= cell == sym;
	}

	bool win_col = true;
	for (const auto& row : _board) {
		win_col &= row.at(col) == sym;
	}

	bool win_diag_main = true;
	bool win_diag_minor = true;
	for (std::size_t i = 0; i < _boardSize; ++i) {
		win_diag_main &= _board.at(_boardSize - i - 1).at(i) == sym;
		win_diag_minor &= _board.at(i).at(i) == sym;
	}

	if (win_row || win_col || win_diag_main || win_diag_minor) {
		_finished = true;
		_status = sym == CellStatus::X ? GameStatus::WinX : GameStatus::WinO;
	}
	else if (_moves_cnt == _moves_max) {
		_finished = true;
		_status = GameStatus::Draw;
	}
}

std::vector<int> Board::findAvailableLocalMoves() {
	std::vector<int> local_moves;

	for (int i = _boardSize - 1; i >= 0; --i) {
		for (int j = 0; j < _boardSize; ++j) {
			auto cell = _board.at(i).at(j);
			if (cell == CellStatus::Empty && hasNeighbors(i, j)) {
				local_moves.push_back(_boardSize * i + j);
			}
		}
	}

	return local_moves;
}

bool Board::hasNeighbors(int i, int j) {
	for (int k = i - 1; k < _boardSize && k <= i + 1; ++k) {
		for (int m = j - 1; m < _boardSize && m <= j + 1; ++m) {
			if (k >= 0 && m >= 0 && _board.at(k).at(m) != CellStatus::Empty) {
				return true;
			}
		}
	}

	return false;
}

std::vector<int> Board::findAvailableMoves() {
	if (_board.size() > 3)
		return findAvailableLocalMoves();

	std::vector<int> moves;

	for (int i = _boardSize - 1; i >= 0; --i) {
		for (int j = 0; j < _boardSize; ++j) {
			auto cell = _board.at(i).at(j);
			if (cell == CellStatus::Empty) {
				moves.push_back(_boardSize * i + j);
			}
		}
	}

	return moves;
}

bool Board::makeMove(int move)
{
	int col = move % _boardSize;
	int row = move / _boardSize;

	if (move < 0 || move > _moves_max || _board.at(row).at(col) != CellStatus::Empty)
		return false;
	
	_moves_cnt++;
	_board.at(row).at(col) = _turn == Turn::X ? CellStatus::X : CellStatus::O;
	evaluate(move);
	_turn = _turn == Turn::X ? Turn::O : Turn::X;

	return true;
}