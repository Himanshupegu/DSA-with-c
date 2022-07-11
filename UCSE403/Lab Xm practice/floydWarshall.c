#include <stdio.h>
#define n 4
#define INF 32000

void printMatrix(int matrix[][n]){
	for(int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
		{
			if(matrix[i][j] == INF){
				printf("%4s", "INF");
			}
			else{
				printf("%4d", matrix[i][j]);
			}
		}
		printf("\n");
	}
}

void floydWarshall(int matrix[][n]){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][k] + matrix[k][j] < matrix[i][j]){
					matrix[i][j] = matrix[i][k] + matrix[k][j]; 
				}
			}
		}
	}
}


int main(){
  int matrix[n][n] = {{0, 8, INF, 1},
                      {INF, 0, 1, INF},
                      {4, INF, 0, INF},
                      {INF, 2, 9, 0}};

  floydWarshall(matrix);
  printMatrix(matrix);


	return 0;
}