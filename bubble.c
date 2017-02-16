#include <stdlib.h>
#include <stdio.h>
#include "bubble.h"

void bubbleSort(int* A, int len)
{
	int key;
	int i;
	for (int j = 1; j < len; j++) {
		key = A[j];
		i = j-1;
		while (i >= 0 && A[i] > key) {
			A[i+1] = A[i];
			i = i - 1;
		}	
		A[i+1] = key;
	}	
}
