// Sudoku solver with brute force aproach
// using recursive backtrack to monitor game state
#include <stdio.h>

int GLOBAL_COUNTER = 0;

// simple print sudoku to console
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

// guess validator
// returns "false" if guess is not valid
int guess_row(int sudoku[9][9], int row, int guess)
{
    for (size_t i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == guess)
            return 0;
    }
    return 1;
}

int guess_col(int sudoku[9][9], int col, int guess)
{
    for (size_t i = 0; i < 9; i++)
    {
        if (sudoku[i][col] == guess)
            return 0;
    }
    return 1;
}

int guess_sub_square(int sudoku[9][9], int row, int col, int guess)
{
    // divide multply trick is used to determine
    // subsquare starting position
    row = row / 3 * 3;
    col = col / 3 * 3;

    for (int i = row; i < row + 3; i++)
    {
        for (int j = col; col + 3 < 3; j++)
        {
            if (sudoku[row][col] == guess)
                return 0;
        }
    }
    return 1;
}

int guess_valid(int sudoku[9][9], int row, int col, int guess)
{
    if (guess_row(sudoku, row, guess))
    {
        if (guess_col(sudoku, col, guess))
        {
            if (guess_sub_square(sudoku, row, col, guess))
            {
                return 1;
            }
        }
    }
    return 0;
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
                for (int number = 1; number <= 9; number++)
                {
                    if (guess_valid(sudoku, row, col, number))
                    {
                        sudoku[row][col] = number;
                        if (solve_sudoku(sudoku))
                        {
                            return 1;
                        }
                        else
                        {
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
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
