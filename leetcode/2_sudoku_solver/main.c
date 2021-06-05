// TODO rename folder to sudoku

// first version prolly will not be ideal
// but hope I get this to work

// arrays starting from 0 and postions starting at 1
// when thinking in math terms is goind to be a problem :)

#include <stdio.h>
struct postion
{
    int row;
    int col;
};

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
}

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

void make_guess(int **sudoku, struct postion p)
{
    // 987 654 321
    // 000 000 000 is 9 byte variable
    // iterate row use logic or to togle bits
    // iterate col use logic or to togle bits
    // find subsquare
    // iterate subsquare use logic or to togle bits
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

    struct postion empty;
    empty = find_next_empty(sudoku);
    printf("\n%d %d \n", empty.row, empty.col);
}
