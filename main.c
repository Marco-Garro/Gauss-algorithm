#include "libs/matrix_lib.h"
#include "libs/pivot.h"


int main(int argc, char* argv[]){
    if(argc != 4){
        printf("USAGE: %s FILENAME #ROWS #COLUMNS\n", argv[0]);
        return -1;
    }

    int rows = atoi(*(argv+2));
    int columns = atoi(*(argv+3));
    float** matrix = readMatrix(argv[1], rows, columns);
    if (matrix == NULL)
        return -1;
    displayMatrix(matrix, rows, columns);
    float* pivot = getPivot(matrix, rows, columns);
    displayMatrix(matrix, rows, columns);
    killColumn(matrix, rows, columns); // pivot always in row: 0 and column: 0
    displayMatrix(matrix, rows, columns);
    return 0;
}
