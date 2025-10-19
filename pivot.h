#ifndef PIVOT_H_
#define PIVOT_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int row;
    int col;
}Pivot;

//prototypes
Pivot* createPivot(int value, int row, int col);
void printPivot(Pivot p);
Pivot** getPivots(int** matrix, int rows, int columns);

//impl
Pivot* createPivot(int value, int row, int col) {
    Pivot* pivot = malloc(sizeof(Pivot));
    pivot->value = value;
    pivot->row = row;
    pivot->col = col;
    return pivot;
}

void printPivot(Pivot p) {
    printf("value: %d, row: %d, col: %d\n", p.value, p.row, p.col);
}

Pivot** getPivots(int** matrix, int rows, int columns) {
    Pivot** pivots = malloc(rows * sizeof(Pivot) + 1);
    int i = 0;
    for (; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            if (matrix[i][j] != 0) {
                *(pivots + i) = createPivot(matrix[i][j], i, j);
                break;
            }
    }
    *(pivots + i) = NULL;
    return pivots;
}

#endif
