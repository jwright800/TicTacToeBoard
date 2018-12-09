/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, piecePlaced) {
	TicTacToeBoard object;
	Piece placed = object.placePiece(0, 0);
	Piece recieved = object.getPiece(0, 0);
	bool result = placed == recieved;
	ASSERT_EQ(result, true);
}

TEST(TicTacToeBoardTest, alreadyPlaced) {
	TicTacToeBoard object;
	Piece placed = object.placePiece(0, 0);
	object.placePiece(0, 0);
	Piece recieved = object.getPiece(0, 0);
	bool result = placed == recieved;
	ASSERT_EQ(result, true);
}

TEST(TicTacToeBoardTest, outOfBounds) {
	TicTacToeBoard object;
	Piece placed = object.placePiece(3, 3);
	bool result = placed == Invalid;
	ASSERT_EQ(result, true);
}

TEST(TicTacToeBoardTest, noWinner) {
	TicTacToeBoard object;
	Piece win = object.getWinner();
	bool result = win == Blank;
	ASSERT_EQ(result, true);
}

TEST(TicTacToeBoardTest, Winner) {
	TicTacToeBoard object;
	Piece placed = object.placePiece(0, 0);
	object.placePiece(0, 1);
	object.placePiece(1, 0);
	object.placePiece(1, 1);
	object.placePiece(2, 0);
	object.placePiece(2, 1);

	Piece recieved = object.getWinner();
	bool result = placed == recieved;
	ASSERT_EQ(result, true);
}

TEST(TicTacToeBoardTest, diagonalWinner) {
	TicTacToeBoard object;
	Piece placed = object.placePiece(0, 0);
	object.placePiece(0, 1);
	object.placePiece(1, 1);
	object.placePiece(1, 2);
	object.placePiece(2, 2);
	object.placePiece(2, 1);

	Piece recieved = object.getWinner();
	bool result = placed == recieved;
	ASSERT_EQ(result, true);
}