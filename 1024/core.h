#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <vector>

using namespace std;

/* The size of the board */
#define SIZE 4

 /* The base used for the exponents */
#define BASE 2

 /* The game board type */
typedef unsigned char Board[][SIZE];

/* Return base^exponent */
unsigned long pow_int(int base, int exponent);

class Game {
private:

public:
	
	Game() {

	}
	~Game() {

	};
	/* Print the board */
	void print_board(const Board board);

	/*
	  Checks if there are possible moves left on the game board.

	  Checks for both movement and combinations of tiles.
	 */
	bool is_game_over(const Board board);

	/* This zeros out the entire game board. */
	void clear_board(Board board);

	/* Adds a value of 1 to random place to the board. */
	void add_random(Board board);

	/*
	 Calculates the score of a game board

	 It scores the board in a simple way.
	 Each element in the board is used as exponents of the BASE. And the
	 sum of all BASE^element is returned.
	 */
	unsigned long calculate_score(const Board board);

	/*
	 Shifts the game board in X direction.

	 It shifts all the elements of the game board in the X direction.
	 If the direction is given as 0, it shifts the game board in the left
	 direction. Any other non zero value shifts it to the right direction.
	 */
	bool shift_x(Board board, bool opp);

	/*
	 Merges the elements in X direction.

	 It merges consecutive successive elements of the game board in the X direction.
	 If the direction is given as 0, it merges the game board to the left
	 direction. Any other non zero value merges it to the right direction.

	 If successful, return true
	 */
	bool merge_x(Board board, bool opp);

	/*
	 Moves the elements in X direction.

	 It simply performs shift_x() and merge_x().
	 If either of them were successful, it also calls add_random()
	 */
	void move_x(Board board, bool opp);

	/*
	 Shifts the game board in Y direction.

	 It shifts all the elements of the game board in the Y direction.
	 If the direction is given as 0, it shifts the game board in the top
	 direction. Any other non-zero value shifts it to the bottom.

	 If successful, return true
	 */
	bool shift_y(Board board, bool opp);

	/*
	 Merges the elements in Y direction

	 It merges consecutive successive elements of the game board in the Y direction.
	 If the direction is given as 0, it merges the game board to the top
	 direction. Any other non zero value merges it to the bottom.
	 */
	bool merge_y(Board board, bool opp);

	/*
	 Moves the elements in Y direction.

	 It simply performs shift_y() and merge_y().
	 If either of them were successful, it also calls add_random()
	 */
	void move_y(Board board, bool opp);
};
