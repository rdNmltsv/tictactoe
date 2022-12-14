#pragma once

#include <vector>
#include <map>
#include "board.h"

enum class GameMode {
	PvE,
	PvP,
	EvE
};

class TicTacToe {
public:	
	TicTacToe(int boardSize, GameMode mode, bool first_move) :
		_board(boardSize),
		_mode(mode),
		_first_move(first_move)
	{}
	
	bool isFinished() { return _board.isFinished(); }
	GameStatus getGameResult() { return _board.getGameStatus(); }

public:
	void printBoard();
	void nextTurn();

private:
	void playerTurn();
	void aiTurn();
	std::pair<int, int> minimax(Board board, bool is_maximizing, int depth, int alpha, int beta);

	
private:
	Board _board;
	GameMode _mode;
	bool _first_move;

	using CacheType = std::map<BoardType, int>;
	CacheType _cache;
};