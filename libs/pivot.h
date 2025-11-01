#ifndef PIVOT_H_
#define PIVOT_H_
#include "matrix_lib.h"


//prototypes
int* getPivot(int** matrix, int rows, int rowOffset, int columnOffset);
int checkZerosColumn(int** matrix, int rows, int rowOffset, int columnOffset);

//impl
inline int* getPivot(int** matrix, int rows, int rowOffset, int columnOffset) {
    int i = rowOffset;
    for (; i < rows; i++) {
        if (matrix[i][columnOffset] != 0) {
            if (!i) {
                printf("pivot: %d\n", *(*(matrix+rowOffset)+columnOffset));
                return *(matrix+rowOffset)+columnOffset;
            }
            swapRows(matrix, rowOffset,i);
            printf("pivot: %d\n", *(*(matrix+rowOffset)+columnOffset));
            return *(matrix+rowOffset)+columnOffset;
        }
    }
    return NULL;
}

inline int checkZerosColumn(int** matrix, int rows, int rowOffset, int columnOffset) {
    int i = rowOffset;
    for (; i < rows; i++) {
        if (matrix[i][columnOffset] != 0) {
            return 0;
        }
    }
    return 1;
}

#endif
