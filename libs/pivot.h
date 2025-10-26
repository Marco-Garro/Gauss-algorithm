#ifndef PIVOT_H_
#define PIVOT_H_
#include "matrix_lib.h"


//prototypes
int* getPivot(int** matrix, int rows);

//impl
inline int* getPivot(int** matrix, int rows) {
    int i = 0;
    printf("rows: %d\n", rows);
    for (; i < rows; i++) {
        if (matrix[i][0] != 0) {
            if (!i)
                return *matrix;
            swapRows(matrix, 0,i);
            return *matrix;
        }
    }
    if (rows == 0)
        return NULL;

    // TODO manage row of zeros
}

#endif
