#include "libs/matrix_lib.h"
#include "libs/pivot.h"

int main(int argc, char* argv[]){
    if(argc != 4){
        printf("USAGE: %s FILENAME #ROWS #COLUMNS\n", argv[0]);
        return -1;
    }

    int rows = atoi(*(argv+2));
    int columns = atoi(*(argv+3));
    int** matrix = readMatrix(argv[1], rows, columns);
    if (matrix == NULL)
        return -1;

    printf("Input Matrix:\n");
    displayMatrix(matrix, rows, columns);

    int** matrixTmp = matrix;
    int rowsTmp = rows;
    int columnsTmp = columns;
    int* pivot = getPivot(matrix, rows);

    while (pivot) {
        killColumn(matrixTmp, rowsTmp, columnsTmp);
        matrixTmp = getSubmatrix(matrixTmp, rowsTmp, !(matrixTmp == matrix));
        rowsTmp--;
        columnsTmp--;
        pivot = getPivot(matrixTmp, rowsTmp);
    }

    printf("Output Matrix:\n");
    displayMatrix(matrix, rows, columns);
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}