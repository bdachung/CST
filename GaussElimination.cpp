#include <iostream>
#include <time.h>
using namespace std;

void gauss(double** matrix, int rows, int cols){
  for(int i = 0 ; i < rows; i++){
    for(int j = 0 ; j < i; j++){
      double coef = matrix[i][j]/matrix[j][j];
      for(int k = j; k < cols; k++){
        matrix[i][k] = matrix[i][k] - coef*matrix[j][k];
      }
    }
  }
}

void print(double** matrix, int rows, int cols){
  for(int i = 0 ; i < rows ; i++){
    for(int j = 0 ; j < cols ; j++){
      printf("%7.2lf ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  srand (time(NULL));
  cout << "Enter number of rows: " ;
  int rows; 
  cin >> rows;
  cout << "Enter number of cols: " ;
  int cols;
  cin >> cols;
  double** matrix = new double*[rows];
  for(int i = 0 ; i < rows ; i++){
    matrix[i] = new double[cols];
    for(int j = 0 ; j < cols ; j++){
      matrix[i][j] = (rand() % 10 + 1) ;
    }
  }
  print(matrix,rows,cols);
  gauss(matrix,rows,cols);
  print(matrix,rows,cols);
  for(int i = 0 ; i < rows ; i++){
      delete[] matrix[i];
  }
  delete matrix;
}