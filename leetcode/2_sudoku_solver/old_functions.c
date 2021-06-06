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