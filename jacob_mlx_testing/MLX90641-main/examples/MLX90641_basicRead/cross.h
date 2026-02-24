#ifndef cross.h
#define cross.h

#include <Arduino.h>
#include <stdio.h>
#include <vector>
using namespace std; 

#define ROWS 12
#define COLS 16
#define ARM  1

int is_cross(int grid[ROWS][COLS], int row, int col);
vector<int> find_crosses(int grid[ROWS][COLS]);

#endif