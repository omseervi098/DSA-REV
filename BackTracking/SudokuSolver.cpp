/*
Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
Sample Input 1:
9 0 0 0 2 0 7 5 0
6 0 0 0 5 0 0 4 0
0 2 0 4 0 0 0 1 0
2 0 8 0 0 0 0 0 0
0 7 0 5 0 9 0 6 0
0 0 0 0 0 0 4 0 1
0 1 0 0 0 5 0 8 0
0 9 0 0 7 0 0 0 4
0 8 2 0 4 0 0 0 6
Sample Output 1:
true
*/
#define N 9
class Solution
{
    public:
    void print(vector<vector<char>> &arr)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }

    // Checks whether it will be
    // legal to assign num to the
    // given row, col
    bool isSafe(vector<vector<char>> &grid, int row,
                int col, char num)
    {

        // Check if we find the same num
        // in the similar row , we
        // return false
        for (int x = 0; x <= 8; x++)
            if (grid[row][x] == num)
                return false;

        // Check if we find the same num in
        // the similar column , we
        // return false
        for (int x = 0; x <= 8; x++)
            if (grid[x][col] == num)
                return false;

        // Check if we find the same num in
        // the particular 3*3 matrix,
        // we return false
        int startRow = row - row % 3,
            startCol = col - col % 3;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (grid[i + startRow][j +
                                       startCol] == num)
                    return false;

        return true;
    }

    /* Takes a partially filled-in grid and attempts
    to assign values to all unassigned locations in
    such a way to meet the requirements for
    Sudoku solution (non-duplication across rows,
    columns, and boxes) */
    bool solvesudoku(vector<vector<char>> &grid, int row, int col)
    {
        // Check if we have reached the 8th
        // row and 9th column (0
        // indexed matrix) , we are
        // returning true to avoid
        // further backtracking
        if (row == N - 1 && col == N)
            return true;

        // Check if column value  becomes 9 ,
        // we move to next row and
        //  column start from 0
        if (col == N)
        {
            row++;
            col = 0;
        }

        // Check if the current position of
        // the grid already contains
        // value >0, we iterate for next column
        if (grid[row][col] !='.')
            return solvesudoku(grid, row, col + 1);

        for (int num = 1; num <= N; num++)
        {

            // Check if it is safe to place
            // the num (1-9)  in the
            // given row ,col  ->we
            // move to next column
            if (isSafe(grid, row, col, num+'0'))
            {

                /* Assigning the num in
                   the current (row,col)
                   position of the grid
                   and assuming our assigned
                   num in the position
                   is correct     */
                grid[row][col] = num+'0';

                //  Checking for next possibility with next
                //  column
                if (solvesudoku(grid, row, col + 1))
                    return true;
            }

            // Removing the assigned num ,
            // since our assumption
            // was wrong , and we go for
            // next assumption with
            // diff num value
            grid[row][col] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        if(solvesudoku(board,0,0))
            print(board);
    }
};