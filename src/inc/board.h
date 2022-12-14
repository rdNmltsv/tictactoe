#pragma once

#include <vector>

enum class CellStatus {
	Empty,
	X,
	O
};

enum class Turn {
	X,
	O
};

enum class GameStatus {
	InProgress,
	WinX,
	WinO,
	Draw
};


using BoardType = std::vector<std::vector<CellStatus>>;

class Board {
public:
	Board(int size) :
		_boardSize(size),
		_board(_boardSize, std::vector<CellStatus>(size)),
		_finished(false),
		_status(GameStatus::InProgress),
		_turn(Turn::X),
		_moves_cnt(0),
		_moves_max(_boardSize * _boardSize)
	{}

	Board(const Board& other) = default;
	Board& operator=(const Board& other) = default;
	Board(Board&& other) = default;
	Board& operator=(Board&& other) = default;
	~Board() = default;

public:
	const int getSize() const { return _boardSize * _boardSize; }
	const BoardType& getPosition() const { return _board; }
	bool isFinished() { return _finished; }
	GameStatus getGameStatus() { return _status; }
	Turn getTurn() { return _turn; }

public:
	void print();
	std::vector<int> findAvailableMoves();
	bool makeMove(int move);

private:
	void evaluate(int move);
	std::vector<int> findAvailableLocalMoves();
	bool hasNeighbors(int i, int j);

private:
	const int _boardSize;
	BoardType _board;
	bool _finished;
	GameStatus _status;
	Turn _turn;
	int _moves_cnt;
	const int _moves_max;
};
