#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X){
    return O;
  } else {
    return X;
  }
  return Invalid;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if (row >= BOARDSIZE || column >= BOARDSIZE) {
    return Invalid;
  }
  if (board[row][column] == Blank) {
    board[row][column] = turn;
    Piece placed = turn;
    if(turn == X) {
      turn = O;
    } else {
      turn = X;
    }
    return placed;
  } else {
    return getPiece(row, column);
  }
  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if (row >= BOARDSIZE || column >= BOARDSIZE) {
    return Invalid;
  } else {
    return board[row][column];
  }
  return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  if (getPiece(0, 0) == getPiece(0, 1) && getPiece(0, 0) != Blank) {
    if(getPiece(0, 0) == getPiece(0, 2)) {
      return getPiece(0, 0);
    }
  }
  if (getPiece(1, 0) == getPiece(1, 1) && getPiece(1, 0) != Blank) {
    if(getPiece(1, 0) == getPiece(1, 2)) {
      return getPiece(1, 0);
    }
  }
  if (getPiece(2, 0) == getPiece(2, 1) && getPiece(2, 0) != Blank) {
    if(getPiece(2, 0) == getPiece(2, 2)) {
      return getPiece(2, 0);
    }
  }
  if (getPiece(0, 0) == getPiece(1, 0) && getPiece(0, 0) != Blank) {
    if(getPiece(0, 0) == getPiece(2, 0)) {
      return getPiece(0, 0);
    }
  }
  if (getPiece(0, 1) == getPiece(1, 1) && getPiece(0, 1) != Blank) {
    if(getPiece(0, 1) == getPiece(2, 1)) {
      return getPiece(0, 1);
    }
  }
  if (getPiece(0, 2) == getPiece(1, 2) && getPiece(0, 2) != Blank) {
    if(getPiece(0, 2) == getPiece(2, 2)) {
      return getPiece(0, 2);
    }
  }
  if (getPiece(0, 0) == getPiece(1, 1) && getPiece(0, 0) != Blank) {
    if(getPiece(0, 0) == getPiece(2, 2)) {
      return getPiece(0, 0);
    }
  }
  if (getPiece(0, 2) == getPiece(1, 1) && getPiece(0, 2) != Blank) {
    if(getPiece(1, 1) == getPiece(2, 0)) {
      return getPiece(1, 1);
    }
  }
  bool not_over = false;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if (getPiece(i, j) == Blank) {
        not_over = true;
      }
    }
  }
  if(not_over == true) {
    return Blank;
  }
  return Invalid;
}
