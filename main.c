#include "matrix_lib.h"
#include "pivot.h"


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

    displayMatrix(matrix, rows, columns);
    Pivot** pivots = getPivots(matrix, rows, columns);

    Pivot* firstPivot = *pivots;
    killColumn(matrix, firstPivot, rows, columns);
    return 0;
}
