//first run to get input
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define Max 1000

void genMatrix(int** a,int n, int m) {
	srand(time(NULL));
	int i,j;
	for(i=0; i< n; i++) {
		for (j=0; j<m; j++) {
			a[i][j] = rand()% 1000;
		}
	} 
}

void output(char* name, int **a, int n, int m) {
	FILE *f ;
	f = fopen (name, "w");
	int i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			fprintf(f, "%d ",a[i][j]);
		}
			fprintf(f, "\n");
	}
	fclose(f);
}

int main () {
	int** a;
	int n = 9800;
	int m = 9800;

	a = malloc(sizeof(int*) * n);
	size_t i;
	for (i = 0; i < n; i++) {
	  a[i] = malloc(sizeof(int) * m);
	}

	genMatrix (a,n, m);
	output("a.txt", a, n, m);
	
	return 0;

}

