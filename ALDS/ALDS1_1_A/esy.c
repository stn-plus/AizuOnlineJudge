// Aizu Onlime Judge
// ALDS1_1_A:   Insertion Sort
// Created esy-na

#include <stdio.h>

#define N 100

void output(int A[], int n);
void insertionSort(int A[], int n);

void output(int A[], int n){
	int i;
	for(i=0; i<(n-1); i++){
		printf("%d ", A[i]);
	}
	printf("%d\n", A[i]);
}

void insertionSort(int *A, int n){
	int i, j, v;

	for(i=1; i<=(n-1); i++){
		v = A[i];
		j = i - 1;
		while( (j>=0) && (A[j] > v) ){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		output(A, n);	//Output Array
	}
}

int main(){
	int n, i;
	int A[N+1];

	//Read first line
	scanf("%d", &n);

	//Read second line's numbers
	for ( i = 1; i <= n; i++ ) scanf("%d", &A[i-1]);

	output(A, n);	//Output Array
	insertionSort(A, n);	//Sort Array

	return 0;
}
