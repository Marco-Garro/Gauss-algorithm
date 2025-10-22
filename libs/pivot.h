#ifndef PIVOT_H_
#define PIVOT_H_
#include "matrix_lib.h"


//prototypes
float* getPivot(float** matrix, int rows, int columns);

//impl
inline float* getPivot(float** matrix, int rows, int columns) {
    int i = 0;
    for (; i < rows; i++) {
        if (matrix[i][0] != 0) {
            if (!i)
                return *matrix;
            swapRows(matrix, 0,i);
            return *matrix;
        }
    }
    return NULL;
}

#endif
