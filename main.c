#include <stdio.h>
#include <stdbool.h>

static const int GRID_SIZE = 9;


static void printBoard(int board[9][9]);
static bool isNumberInRow(int board[9][9], int number, int row);
static bool isNumberInColumn(int board[9][9], int number, int column);
static bool isNumberInBox(int board[9][9], int number, int row, int column);
static bool isValidPlacement(int board[9][9], int number, int row, int column);
static bool solveBoard(int board[9][9]);



int main() {
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

    printBoard(board);
    putchar('\n');

    if (solveBoard(board)) {
        printf("Solved successfully!\n");
    }
    else {
        printf("Unsolvable board :(\n");
        return 1;
    }

    printBoard(board);

    return 0;
}




static void printBoard(int board[9][9]) {
    for (int row = 0; row < GRID_SIZE; row++) {
        if (row % 3 == 0 && row != 0) {
            printf("-----------\n");
        }
        for (int column = 0; column < GRID_SIZE; column++) {
            if (column % 3 == 0 && column != 0) {
                putchar('|');
            }
            printf("%d", board[row][column]);
        }
        putchar('\n');
    }
}


static bool isNumberInRow(int board[9][9], int number, int row) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (board[row][i] == number) {
            return true;
        }
    }
    return false;
}

static bool isNumberInColumn(int board[9][9], int number, int column) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (board[i][column] == number) {
            return true;
        }
    }
    return false;
}

static bool isNumberInBox(int board[9][9], int number, int row, int column) {
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

static bool isValidPlacement(int board[9][9], int number, int row, int column) {
    return !isNumberInRow(board, number, row) &&
           !isNumberInColumn(board, number, column) &&
           !isNumberInBox(board, number, row, column);
}

static bool solveBoard(int board[9][9]) {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int column = 0; column < GRID_SIZE; column++) {
            if (board[row][column] == 0) {
                for (int numberToTry = 1; numberToTry <= GRID_SIZE; numberToTry++) {
                    if (isValidPlacement(board, numberToTry, row, column)) {
                        board[row][column] = numberToTry;

                        if (solveBoard(board)) {
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
