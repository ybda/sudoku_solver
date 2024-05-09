#include "./sudoku_solver.h"
#include <stdio.h>

static bool sudokuSolver_isValidPlacement(int[SUDOKU_SOLVER_GRID_SIZE][SUDOKU_SOLVER_GRID_SIZE], int, int, int);

void sudokuSolver_printBoard(int board[SUDOKU_SOLVER_GRID_SIZE][SUDOKU_SOLVER_GRID_SIZE]) {
    for (int row = 0; row < SUDOKU_SOLVER_GRID_SIZE; row++) {
        if (row % 3 == 0 && row != 0) {
            printf("-----------\n");
        }
        for (int column = 0; column < SUDOKU_SOLVER_GRID_SIZE; column++) {
            if (column % 3 == 0 && column != 0) {
                putchar('|');
            }
            printf("%d", board[row][column]);
        }
        putchar('\n');
    }
}

bool sudokuSolver_solveBoard(int board[SUDOKU_SOLVER_GRID_SIZE][SUDOKU_SOLVER_GRID_SIZE]) {
    for (int row = 0; row < SUDOKU_SOLVER_GRID_SIZE; row++) {
        for (int column = 0; column < SUDOKU_SOLVER_GRID_SIZE; column++) {
            if (board[row][column] == 0) {
                for (int numberToTry = 1; numberToTry <= SUDOKU_SOLVER_GRID_SIZE; numberToTry++) {
                    if (sudokuSolver_isValidPlacement(board, numberToTry, row, column)) {
                        board[row][column] = numberToTry;

                        if (sudokuSolver_solveBoard(board)) {
                            return true;
                        }
                        else {
                            board[row][column] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

static bool sudokuSolver_isNumberInRow(int board[SUDOKU_SOLVER_GRID_SIZE][SUDOKU_SOLVER_GRID_SIZE], int number, int row) {
    for (int i = 0; i < SUDOKU_SOLVER_GRID_SIZE; i++) {
        if (board[row][i] == number) {
            return true;
        }
    }
    return false;
}



static bool sudokuSolver_isNumberInColumn(int board[SUDOKU_SOLVER_GRID_SIZE][SUDOKU_SOLVER_GRID_SIZE], int number, int column) {
    for (int i = 0; i < SUDOKU_SOLVER_GRID_SIZE; i++) {
        if (board[i][column] == number) {
            return true;
        }
    }
    return false;
}

static bool sudokuSolver_isNumberInBox(int board[SUDOKU_SOLVER_GRID_SIZE][SUDOKU_SOLVER_GRID_SIZE], int number, int row, int column) {
    int localBoxRow = row - row % 3;
    int localBoxColumn = column - column % 3;

    for (int i = localBoxRow; i < localBoxRow + 3; i++) {
        for (int j = localBoxColumn; j < localBoxColumn + 3; j++) {
            if (board[i][j] == number) {
                return true;
            }
        }
    }
    return false;
}

static bool sudokuSolver_isValidPlacement(int board[SUDOKU_SOLVER_GRID_SIZE][SUDOKU_SOLVER_GRID_SIZE], int number, int row, int column) {
    return !sudokuSolver_isNumberInRow(board, number, row) &&
           !sudokuSolver_isNumberInColumn(board, number, column) &&
           !sudokuSolver_isNumberInBox(board, number, row, column);
}

