#ifndef MATRIX_LIB_H_
#define MATRIX_LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "garro.h"

//prototypes
int** readMatrix(char* filename, int rows, int columns);
char* readLine(FILE* fpr, int columns);
void displayMatrix(int** matrix, int rows, int columns);
int* getColumn(int** matrix, int rows, int column);
void killColumn(int* pivot, int** matrix, int rows, int columns);
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

char* readLine(FILE* fpr, int columns){

    char ret[columns];
    char* tmp = ret;
    char c = fgetc(fpr);
    for(;c != '\n' && c != EOF;tmp++){
        *tmp = c;
        c = fgetc(fpr);
    }
    *tmp = '\0';
    return strdup(ret);
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

void killColumn(int* pivot, int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        int toKill = matrix[i][i];

    }
}

void swapRows(int** matrix, int a, int b){
    int* swap = *(matrix + a);
    *(matrix + a) = *(matrix + b);
    *(matrix + b) = swap;
}
#endif