#ifndef MATRIX_LIB_H_
#define MATRIX_LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include "other_lib.h"

//prototypes
int** readMatrix(char* filename, int rows, int columns);
void displayMatrix(int** matrix, int rows, int columns);
int* getColumn(int** matrix, int rows, int column);
void killColumn(int** matrix, int rows, int columns, int offset);
void swapRows(int** matrix, int a, int b);

//impl
inline int** readMatrix(char* filename, int rows, int columns){
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("cannot open %s", filename);
        return NULL;
    }

    char* csv_matrix[rows];
    for (int i = 0; i < rows; i++)
        *(csv_matrix + i) = readLine(fp, columns);

    int** matrix = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(columns * sizeof(int));
        char** splitted = split(*(csv_matrix + i), ",");
        for (int j = 0; j < columns; j++) {
               matrix[i][j] = atoi(*(splitted + j));
        }
    }
    for (int i = 0; i < rows; i++)
        free(csv_matrix[i]);
    return matrix;
}

inline void displayMatrix(int** matrix, int rows, int columns) {
    putchar('\t');
    for (int i = 0; i < columns; i++)
        printf("|%d|   ", i+1);
    printf("\n\n");
    for (int i = 0; i < rows; i++) {
        printf("|%d|\t", i+1);
        for (int j = 0; j < columns; j++)
            printf(" %d    ", matrix[i][j]);
        printf("\n\n");
    }
}

inline int* getColumn(int** matrix, int rows, int column) {
    int* cols = malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++)
        *(cols + i) = matrix[i][column];

    return cols;
}

inline void killColumn(int** matrix, int rows, int columns, int offset) {
    int pivot = matrix[offset][offset];
    for (int i = offset+1; i < rows; i++) {
        if (matrix[i][offset] != 0) {
            int toKill = matrix[i][offset];
            for (int j = offset; j < columns; j++) {
                matrix[i][j] *= pivot;
                matrix[i][j] -= matrix[offset][j] * toKill;
            }
        }
    }
}

inline void swapRows(int** matrix, int a, int b){
    int* swap = *(matrix + a);
    *(matrix + a) = *(matrix + b);
    *(matrix + b) = swap;
}
#endif