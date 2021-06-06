// TODO rename folder to sudoku

// first version prolly will not be ideal
// but hope I get this to work

// arrays starting from 0 and postions starting at 1
// when thinking in math terms is goind to be a problem :)

// prolly need to comment alot cos cos of all the spagetti

#include <stdio.h>
struct postion
{
    int row;
    int col;
};

// simple print for 9x9 sudoku
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

// finds next empty postion in 9x9 sudoku
struct postion find_next_empty(int sudoku[9][9])
{
    int row, col;
    struct postion p;
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (sudoku[row][col] == 0)
            {
                p.row = row;
                p.col = col;
                return p;
            }
        }
    }
    // not shure if needed but returns 10 10 when no empty squares
    p.row = 9;
    p.col = 9;
    return p;
}

// test if guess is found on row
int guess_row(int sudoku[9][9], struct postion p, int guess)
{

    for (size_t i = 0; i < 9; i++)
    {
        if (sudoku[p.row][i] == guess)
            return 0;
    }
    return 1;
}

// test if guess is found on col
int guess_col(int sudoku[9][9], struct postion p, int guess)
{

    for (size_t i = 0; i < 9; i++)
    {
        if (sudoku[i][p.col] == guess)
            return 0;
    }
    return 1;
}

// test if guess is found on sub square
int guess_sub_square(int sudoku[9][9], struct postion p, int guess)
{
    int row_start = p.row / 3 * 3;
    int col_start = p.col / 3 * 3;

    for (size_t row = 0; row < 3; row++)
    {
        for (size_t col = 0; col < 3; col++)
        {
            if (sudoku[row][col] == guess)
                return 0;
        }
    }
    return 1;
}

// combined guess function
int guess_valid(int sudoku[9][9], struct postion p, int guess)
{
    if (guess_row(sudoku, p, guess))
    {
        if (guess_col(sudoku, p, guess))
        {
            if (guess_sub_square(sudoku, p, guess))
            {
                printf("guess %d is valid\n", guess);
                return 1;
            }
        }
    }
    printf("guess %d not valid\n", guess);
    return 0;
}

int solve_sudoku(int sudoku[9][9])
{

    struct postion p = find_next_empty(sudoku);
    // TODO empty cell gets wrong postions
    printf("\nempty cell is %d %d \n", p.row, p.col);
    if (p.row == 9 && p.col == 9)
    {
        printf("ends in here");
        return 1;
    }

    for (int guess = 1; guess <= 9; guess++)
    {
        if (guess_valid(sudoku, p, guess))
        {
            printf("placing guess %d to [%d][%d]\n", guess, p.row + 1, p.col + 1);
            sudoku[p.row][p.col] = guess;
            print_sudoku(sudoku);
            solve_sudoku(sudoku);
        }
    }
    printf("return one layer back\n");
    return 0;
}

void main()
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

    print_sudoku(sudoku);

    solve_sudoku(sudoku);

    // now how to write recursive funcion that solves the sudoku???
}
