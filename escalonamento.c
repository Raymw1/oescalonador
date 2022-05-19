#include <stdio.h>
#include <math.h>

void askRowsAndColumns(int *rows, int *cols);
void createMatrix(int rows, int cols, int *matrix);

int main(void) {
  int rows, cols, matrix;
  askRowsAndColumns(&rows, &cols);
  createMatrix(rows, cols, &matrix);
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      printf("%i ", matrix[row][col]);
    }
    printf("\n");
  }
  printf("That'll be %ix%i\n", rows, cols);
  return 0;
}

void askRowsAndColumns(int *rows, int *cols) {
  printf("How many rows? ");
  scanf("%d", rows);
  printf("How many columns? ");
  scanf("%d", cols);
}

void createMatrix(int rows, int cols, int *matrix) {
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      printf("Enter the value for A[%i][%i]: ", row+1, col+1);
      scanf("%d", matrix[row][col]);
    }
  }
}