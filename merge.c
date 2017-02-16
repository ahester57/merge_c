#include <stdlib.h>
#include <stdio.h>
#include "merge.h"
#include <math.h>
#include <limits.h>
// merge sort

void mergeSort(int* A, int p, int r)
{
	if (p < r) {
		int k = (p+r) / 2;	
		mergeSort(A, p, k);
		mergeSort(A, k+1, r);
		merge(A, p, k, r);
	}
}

void merge(int* A, int p, int q, int r)
{
	int n1 = q - p +1 ;
	int n2 = r - q  ;		//num of items in each half
	int* L = malloc((n1+1) * sizeof(int));
	int* R = malloc((n2+1) * sizeof(int));
	

	for (int i = 0; i < n1; i++) {
		L[i] = A[p + i -1 ];	
	}
	for (int j = 0; j < n2; j++) {
		R[j] = A[q + j ];
	}

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int b = 0;
	int c = 0;


	for (int k = p-1; k < r; k++) {
		if (L[b] < R[c] ) {
			A[k] = L[b];
			b++;
		} else {
			A[k] = R[c];
			c++;
		}
	}

	free(L);

	free(R);
}


	
