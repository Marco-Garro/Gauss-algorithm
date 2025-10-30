#ifndef PIVOT_H_
#define PIVOT_H_
#include "matrix_lib.h"


//prototypes
int* getPivot(int** matrix, int rows, int offset);
int checkZerosColumn(int** matrix, int rows, int offset);

//impl
inline int* getPivot(int** matrix, int rows, int offset) {
    int i = offset;
    for (; i < rows; i++) {
        if (matrix[i][offset] != 0) {
            if (!i) {
                printf("pivot: %d\n", *(*(matrix+offset)+offset));
                return *(matrix+offset)+offset;
            }
            swapRows(matrix, offset,i);
            printf("pivot: %d\n", *(*(matrix+offset)+offset));
            return *(matrix+offset)+offset;
        }
    }
    return NULL;
}

inline int checkZerosColumn(int** matrix, int rows, int offset) {
    int i = offset;
    for (; i < rows; i++) {
        if (matrix[i][offset] != 0) {
            return 0;
        }
    }
    return 1;
}

#endif
