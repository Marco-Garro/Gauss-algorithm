#include "libs/matrix_lib.h"
#include "libs/pivot.h"

int main(int argc, char* argv[]){
    if(argc != 4){
        printf("USAGE: %s FILENAME #ROWS #COLUMNS\n", argv[0]);
        return -1;
    }

    int rows = atoi(*(argv+2));
    int columns = atoi(*(argv+3));
    int** matrix = readMatrix(*(argv+1), rows, columns);
    if (matrix == NULL)
        return -1;

    printf("Input Matrix:\n");
    displayMatrix(matrix, rows, columns);

    int rowOffset = 0;
    int columnOffset = 0;
    while (checkZerosColumn(matrix, rows, rowOffset, columnOffset) && columnOffset <= rows)
        columnOffset++;

    int* pivot = getPivot(matrix, rows, rowOffset, columnOffset);
    while (pivot) {
        killColumn(matrix, rows, columns, rowOffset, columnOffset);
        printf("after kill\n");
        displayMatrix(matrix, rows, columns);

        rowOffset++;
        while (checkZerosColumn(matrix, rows, rowOffset, columnOffset) && columnOffset <= rows)
            columnOffset++;
        pivot = getPivot(matrix, rows, rowOffset, columnOffset);
    }

    printf("Output Matrix:\n");
    displayMatrix(matrix, rows, columns);
    for (int i = 0; i < rows; i++)
        free(matrix[i]);

    free(matrix);
    return 0;
}