// Sudoku solver with brute force aproach
// using recursive backtrack to monitor game state
#include <stdio.h>

#define FALSE 0
#define TRUE 1

unsigned GLOBAL_COUNTER = 0;

void print_sudoku(int sudoku[9][9])
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            if (j == 3 || j == 6)
                printf("   ");
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
        if (i == 2 || i == 5)
            printf("\n");
    }
    printf("\n");
}

// 3 validator functions and one supervalidator
int validate_row(int sudoku[9][9], int row, int guess)
{
    for (size_t i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == guess)
            return FALSE;
    }
    return TRUE;
}

int validate_col(int sudoku[9][9], int col, int guess)
{
    for (size_t i = 0; i < 9; i++)
    {
        if (sudoku[i][col] == guess)
            return FALSE;
    }
    return TRUE;
}

int validate_sub_square(int sudoku[9][9], int row, int col, int guess)
{
    // divide multply trick is used to determine
    // in which subsquare we are
    row = row / 3 * 3;
    col = col / 3 * 3;

    for (int i = row; i < row + 3; i++)
    {
        for (int j = col; col + 3 < 3; j++)
        {
            if (sudoku[row][col] == guess)
                return FALSE;
        }
    }
    return TRUE;
}

int validate_guess(int sudoku[9][9], int row, int col, int guess)
{
    if (validate_row(sudoku, row, guess))
    {
        if (validate_col(sudoku, col, guess))
        {
            if (validate_sub_square(sudoku, row, col, guess))
            {
                return TRUE;
            }
        }
    }
    return FALSE;
}

// recursive backtracking algo
// as stated in NASA docs
// never write code like this :))
// fun experiment tough

int solve_sudoku(int sudoku[9][9])
{
    GLOBAL_COUNTER++;
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (sudoku[row][col] == 0)
            {
                for (int guess = 1; guess <= 9; guess++)
                {
                    if (validate_guess(sudoku, row, col, guess))
                    {
                        sudoku[row][col] = guess;
                        if (solve_sudoku(sudoku))
                        {
                            return TRUE;
                        }
                        else
                        {
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return FALSE;
            }
        }
    }
    return TRUE;
}

int main()
{
    int sudoku[9][9] = {
        {9, 0, 0, 0, 7, 0, 0, 0, 0},
        {2, 0, 0, 0, 9, 0, 0, 5, 3},
        {0, 6, 0, 0, 1, 2, 4, 0, 0},
        {8, 4, 0, 0, 0, 1, 0, 9, 0},
        {5, 0, 0, 0, 0, 0, 8, 0, 0},
        {0, 3, 1, 0, 0, 4, 0, 0, 0},
        {0, 0, 3, 7, 0, 0, 6, 8, 0},
        {0, 9, 0, 0, 5, 0, 7, 4, 1},
        {4, 7, 0, 0, 0, 0, 0, 0, 0}};

    solve_sudoku(sudoku);
    print_sudoku(sudoku);
    printf("%d functions used to solve this sudoku\n", GLOBAL_COUNTER);
}
