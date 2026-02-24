#include <stdio.h>
#include <vector>
#include "cross.h"

using namespace std; 

#define ROWS 12
#define COLS 16
#define ARM  1

int is_cross(int grid[ROWS][COLS], int row, int col)
{
    int i;

    if (grid[row][col] != 1)
        return 0;

    for (i = 1; i <= ARM; i++) {
        if (row - i < 0    || grid[row - i][col] != 1) return 0;
        if (row + i >= ROWS || grid[row + i][col] != 1) return 0;
        if (col - i < 0    || grid[row][col - i] != 1) return 0;
        if (col + i >= COLS || grid[row][col + i] != 1) return 0;
    }

    return 1;
}

vector<int> find_crosses(int grid[ROWS][COLS])
{
    int r, c, found = 0;
    //int position[2][1];
    int current_r, current_c = 0; 

    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            if (is_cross(grid, r, c)) {
                current_r = r;
                current_c = c;
                //found++;
                found = 1;
            }
        }
    }
    //position[1][1] = current_r;
    //position[2][1] = current_c;
    
    vector<int> return_vec; 
    return_vec.push_back(current_r);
    return_vec.push_back(current_c);
    return_vec.push_back(found);

    return return_vec; 
}