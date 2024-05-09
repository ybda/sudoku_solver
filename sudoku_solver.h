#ifndef SUDOKU_SOLVER_SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_SUDOKU_SOLVER_H


#include <stdbool.h>

static const int SUDOKU_SOLVER_GRID_SIZE = 9;
void sudokuSolver_printBoard(int board[SUDOKU_SOLVER_GRID_SIZE][SUDOKU_SOLVER_GRID_SIZE]);
bool sudokuSolver_solveBoard(int board[SUDOKU_SOLVER_GRID_SIZE][SUDOKU_SOLVER_GRID_SIZE]);


#endif //SUDOKU_SOLVER_SUDOKU_SOLVER_H
