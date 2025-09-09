/*Takes 2 matrices A and B of size m x n as an input from user.
Computes their sum: C = A + B -> Prints the resulting matrix C in a clear tabular format
Program should ask user to enter rows(m) and columns(n)
Dynamically reads value for both matrices, Outputs all 3 matrices for clarity.
Constraints: Max matrix size is 10x10, Should give an error if matrix dimensions are not the same.*/
//Bro this feels like solving integral after learning addition and substraction in first grade lmao. Lets see!
//Alright I did it. and I hope I'm freeing the memory correctly :DD

#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int rows, int cols);
void buildingMatrix(int** matrix, int m, int n);
void matrixAddition(int** A, int** B, int** C, int m, int n);
void printAddition(int** A, int** B, int** C, int m, int n);

int main(){
    int m, n;
    printf("Please give the matrix size in the order of rows and columns(MAX 10x10): \n");
    scanf("%d %d", &m, &n); //printf("%d %d", m, n);//testing -> It works
    if(m > 10 || m <= 0 || n > 10 || n <= 0){
        return -1;
    }
    int** pointA = createMatrix(m, n);//The reason we're taking a pointer to a pointer is pointA will point to
    int** pointB = createMatrix(m, n);//
    int** pointC = createMatrix(m, n);
    
    printf("Enter the FIRST matrix row by row from left to right, one by one: \n");
    buildingMatrix(pointA, m, n);
    printf("Enter the SECOND matrix row by row from left to right, one by one: \n");
    buildingMatrix(pointB, m, n);

    matrixAddition(pointA, pointB, pointC, m, n);
    printAddition(pointA, pointB, pointC, m, n);

    for(int i = 0; i < m; i++){
        free(pointA[i]);
    }
    free(pointA);

    for(int i = 0; i < m; i++){
        free(pointB[i]);
    }
    free(pointB);

    
    for(int i = 0; i < m; i++){
        free(pointC[i]);
    }
    free(pointC);

    return 0;
}

int** createMatrix(int rows, int cols){
    int** matrix = malloc(rows * sizeof(int*)); //A (rows) sized array of pointers (Each will point to a row's first index soon)
    for(int i = 0; i < rows; i++){
        matrix[i] = malloc(cols * sizeof(int)); //Each of these will point to the [rows][cols]'s address
    }                                           //Something like that. Think about it 2 mins you'll realize whats happening
    return matrix;
}

void buildingMatrix(int** matrix, int m, int n){
    int value;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Matrix[%d][%d]: ", i+1, j+1);
            scanf("%d", &value);
            matrix[i][j] = value;
        }
    }
}

void matrixAddition(int** A, int** B, int** C, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void printAddition(int** A, int** B, int** C, int m, int n){
    for(int i = 0; i < m; i++){
        for(int a = 0; a < n; a++){
            printf("%-2d ", A[i][a]);
        }
        printf("   ");
        for(int b = 0; b < n; b++){
            printf("%-2d ", B[i][b]);
        }
        printf("   ");
        for(int c = 0; c < n; c++){
            printf("%-2d ", C[i][c]);
        }
    printf("\n");
    }
}