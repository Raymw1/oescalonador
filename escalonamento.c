#include <stdio.h>
#include "matrix.h"

int main(void)
{
    // Creating a matrix instance
    Matrix *matrix = init_matrix(matrix);
    matrix->createMatrix(matrix);
    matrix->printRowsCols(matrix);
    return 0;
}
