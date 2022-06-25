#include <stdlib.h>

// Defining structure of Matrix (same as a class)
typedef struct Matrix Matrix;
struct Matrix {
	// Parameters
	int rows;
	int cols;
	float **matrix_entry;

	// Methods
	void (*setRowsCols)(Matrix *);
	void (*printRowsCols)(Matrix *);
	void (*createMatrix)(Matrix *);
};

// Initializng functions
void set_rows_cols (Matrix *obj);
void print_rows_cols(Matrix *obj);
void createMatrix(Matrix *obj);

// Configuring the matrix (this function return a object pointer of type Matrix )
Matrix * init_matrix () {
	// Creating the Matrix instance 
	Matrix *matrix = (Matrix *)calloc(1, sizeof(Matrix));
	
	// Define the voids
	matrix->setRowsCols = set_rows_cols;
	matrix->printRowsCols = print_rows_cols;
	matrix->createMatrix = createMatrix;
	
	// Execute the function defined
	matrix->setRowsCols(matrix);
	
	// Creating dynamically matrix and defining length
	matrix->matrix_entry = malloc( matrix->rows *sizeof(float *));
	for(int j = 0 ; j < matrix->rows ; j++)
	{
		matrix->matrix_entry[j] = malloc( matrix->cols*sizeof(float) );
	}

	return matrix;
}

// Set amount rows and collumns 
void set_rows_cols (Matrix *obj) {
	printf("How many rows? ");
	scanf("%d", &obj->rows);
	printf("How many columns? ");
	scanf("%d", &obj->cols);
}

// Print the Matrix
void print_rows_cols(Matrix *obj) {
	for (int row = 0; row < obj->rows; row++) {
		for (int col = 0; col < obj->cols; col++) {
		  printf("%.2f \t", obj->matrix_entry[row][col]);
		}    
	printf("\n");
	}
}

// Creating matrix
void createMatrix(Matrix *obj) {
  for (int row = 0; row < obj->rows; row++) {
	for (int col = 0; col < obj->cols; col++) {
	  printf("Enter the value for A[%i][%i]: ", row+1, col+1);
	  scanf("%f", &obj->matrix_entry[row][col]);
	}
  }
}
