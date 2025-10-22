#ifndef MATRIX_LIB_H_
#define MATRIX_LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "other_lib.h"

//prototypes
int** readMatrix(char* filename, int rows, int columns);
void displayMatrix(int** matrix, int rows, int columns);
int* getColumn(int** matrix, int rows, int column);
float findLambda(int pivot, int element);
void killColumn(int** matrix, int rows, int columns);
void swapRows(int** matrix, int a, int b);

//impl
int** readMatrix(char* filename, int rows, int columns){
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

void displayMatrix(int** matrix, int rows, int columns) {
    putchar('\t');
    for (int i = 0; i < columns; i++)
        printf("%d    ", i+1);
    printf("\n\n");
    for (int i = 0; i < rows; i++) {
        printf("%d\t", i+1);
        for (int j = 0; j < columns; j++)
            printf("%d    ", matrix[i][j]);
        printf("\n\n");
    }
}

int* getColumn(int** matrix, int rows, int column) {
    int* cols = malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++)
        *(cols + i) = matrix[i][column];

    return cols;
}


float findLambda(int pivot, int element) {
    float lambda = 1;
    int sign = pivot > 0?1:-1;
    if (element % pivot == 0) {
        if (pivot < element) {
            while (element + sign*pivot*lambda != 0)
                lambda--;
        }
        else {
            while (element + sign*pivot*lambda != 0)
                lambda/=2;
        }
    }
    else {
        lambda = 30000000;
    }
    return lambda;
}

void killColumn(int** matrix, int rows, int columns) {
    int pivot = matrix[0][0];
    for (int i = 1; i < rows; i++) {
        int toKill = matrix[i][0];
        if (toKill != 0) {
            float lambda = findLambda(pivot, toKill);
            for (int j = 0; j < columns; j++)
                matrix[i][j] += lambda * pivot;     //R_i=>R_i-\lambda*R_j, TODO repeat to the whole row
        }
    }
}

void swapRows(int** matrix, int a, int b){
    int* swap = *(matrix + a);
    *(matrix + a) = *(matrix + b);
    *(matrix + b) = swap;
}
#endif