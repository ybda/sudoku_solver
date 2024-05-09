#include <stdio.h>
#include "./sudoku_solver.h"

int main() {
    printf("--[Source board]--\n\n");
    int board[9][9] = {
            {7, 0, 2, 0, 5, 0, 6, 0, 0},
            {0, 0, 0, 0, 0, 3, 0, 0, 0},
            {1, 0, 0, 0, 0, 9, 5, 0, 0},
            {8, 0, 0, 0, 0, 0, 0, 9, 0},
            {0, 4, 3, 0, 0, 0, 7, 5, 0},
            {0, 9, 0, 0, 0, 0, 0, 0, 8},
            {0, 0, 9, 7, 0, 0, 0, 0, 5},
            {0, 0, 0, 2, 0, 0, 0, 0, 0},
            {0, 0, 7, 0, 4, 0, 2, 0, 3}
    };

    sudokuSolver_printBoard(board);
    putchar('\n');

    if (sudokuSolver_solveBoard(board)) {
        printf("--[Solved board]--\n\n");
    }
    else {
        printf("Unsolvable board :(\n");
        return 1;
    }

    sudokuSolver_printBoard(board);

    return 0;
}
