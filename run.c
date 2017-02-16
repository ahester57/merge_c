#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "merge.h"
#include "bubble.h"
#include "handler.h"

// runs sorting fun

int main(int argc, char** argv) {
	FILE* fp;

	// see if there's a cmd line arg
	if (argv[1] != NULL) {
		fp = fopen(argv[1], "r");
	} else { 
		fp = fopen("./400.rnd", "r");
	}

	// get number of numbers in file
	const int LENGTH = getNumLines(fp);


	// allocate enough space
	int* A;
	A = malloc(LENGTH * sizeof(int));
	setArray(A, fp);	// do magic
	fclose(fp);


	double time_taken;

	char* method;
	if (argv[0][0] == 'b' || argv[0][2] == 'b') {
		clock_t begin = clock();
		bubbleSort(A, LENGTH);
		clock_t end = clock();
		time_taken = (double)(end - begin) / CLOCKS_PER_SEC;
		method = "bubble";
	} else {
		clock_t begin = clock();
		mergeSort(A, 0, LENGTH);
		clock_t end = clock();
		time_taken = (double)(end - begin) / CLOCKS_PER_SEC; 
		method = "merge";
	}

	FILE* fq = fopen("./info.log", "a");
	if (fq != NULL) {
		fprintf(fq, "Method:\t%s\n", method);
		fprintf(fq, "Size:\t%d\n", LENGTH);
		fprintf(fq, "Time:\t%f\n", time_taken);
		fprintf(fq, "---------------------------\n");
	}
	fclose(fq);

	FILE* fr = fopen("./sortedArray.log", "w");
	if (fr != NULL) {
		for (int i = 0; i < LENGTH; i++) {
			fprintf(fr, "%d\n", A[i]);
		}
	}

	fclose(fr);
	free(A);
	return 0;
}
