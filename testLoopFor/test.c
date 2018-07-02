#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<omp.h>

void read_matrix(char* file, int** A, int M, int N) {
	FILE *f = fopen(file, "r");
	int i, j;
	for (i = 0; i < M; i++) {
	    for (j = 0; j < N; j++) {
	         if(!fscanf(f, "%d", &A[i][j])) break;
	    }
	}

	fclose(f);
}

int main(){
	int i,j;
	int sum = 0;
	int n = 100;
	int m = 9000;
    int **a = (int **)malloc(n * sizeof(int *));
   for (i = 0; i < n; i++)
      a[i] = (int *)malloc(m * sizeof(int));

    read_matrix("a.txt", a, n, m);
    //Bat dau tinh time
	double t = omp_get_wtime();
	//Khong doi
	for(i = 0; i < n; ++i){
		for(j = 0; j < m; ++j){
			sum += a[i][j];
		}
	}

	//Doi i,j
//	for(j = 0; j < m; ++j){
//		for(i = 0; i < n; ++i)
//		sum+= a[i][j];
//	}
    double time_taken = (omp_get_wtime() - t) * 1000;
    printf("fun() ends\n");
    printf("fun() took %f ms to execute\n", time_taken);
    printf("%d",sum);
	return 0;
}
