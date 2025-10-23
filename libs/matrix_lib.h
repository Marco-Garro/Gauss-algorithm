#ifndef MATRIX_LIB_H_
#define MATRIX_LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "other_lib.h"

//prototypes
float** readMatrix(char* filename, int rows, int columns);
void displayMatrix(float** matrix, int rows, int columns);
float* getColumn(float** matrix, int rows, int column);
void killColumn(float** matrix, int rows, int columns);
void swapRows(float** matrix, int a, int b);

//impl
inline float** readMatrix(char* filename, int rows, int columns){
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("cannot open %s", filename);
        return NULL;
    }

    char* csv_matrix[rows];
    for (int i = 0; i < rows; i++)
        *(csv_matrix + i) = readLine(fp, columns);

    float** matrix = malloc(rows * sizeof(float *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(columns * sizeof(float));
        char** splitted = split(*(csv_matrix + i), ",");
        for (int j = 0; j < columns; j++) {
               matrix[i][j] = atof(*(splitted + j));
        }
    }
    for (int i = 0; i < rows; i++)
        free(csv_matrix[i]);
    return matrix;
}

inline void displayMatrix(float** matrix, int rows, int columns) {
    putchar('\t');
    for (int i = 0; i < columns; i++)
        printf("%d    ", i+1);
    printf("\n\n");
    for (int i = 0; i < rows; i++) {
        printf("%d\t", i+1);
        for (int j = 0; j < columns; j++)
            printf("%.2f    ", matrix[i][j]);
        printf("\n\n");
    }
}

inline float* getColumn(float** matrix, int rows, int column) {
    float* cols = malloc(rows * sizeof(float));
    for (int i = 0; i < rows; i++)
        *(cols + i) = matrix[i][column];

    return cols;
}

inline void killColumn(float** matrix, int rows, int columns) {
    float pivot = matrix[0][0];
    for (int i = 1; i < rows; i++) {
        if (matrix[i][0] != 0) {
            float toKill = matrix[i][0];
            for (int j = 0; j < columns; j++) { // iterate on the column of the pivot
                matrix[i][j] *= pivot;
                matrix[i][j] -= matrix[0][j] * toKill;
            }
        }
    }
}

inline void swapRows(float** matrix, int a, int b){
    float* swap = *(matrix + a);
    *(matrix + a) = *(matrix + b);
    *(matrix + b) = swap;
}
#endif