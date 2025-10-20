#ifndef PIVOT_H_
#define PIVOT_H_
#include <stdio.h>
#include <stdlib.h>


//prototypes
int* getPivot(int** matrix, int rows, int columns);

//impl
int* getPivot(int** matrix, int rows, int columns) {
    int i = 0;
    for (; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (matrix[i][j] != 0)
                return *(matrix+i)+j;
}

#endif
