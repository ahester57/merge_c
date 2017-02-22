#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "merge.h"
#include "bubble.h"
#include "mkrand.h"
#include "handler.h"

double bubble_(int* A, int LENGTH);
double merge_(int* A, int LENGTH);
//void makeRandomList(int cnt);
void makeOutput(const char* method, int* A, int LENGTH, double time_taken);

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
		method = "bubble";
		time_taken = bubble_(A, LENGTH);
	} else {
		method = "merge";
		time_taken = merge_(A, LENGTH);
	}
	

	makeOutput(method, A, LENGTH, time_taken);
	
	free(A);
	return 0;
}

double bubble_(int* A, int LENGTH) {
	clock_t begin = clock();
	bubbleSort(A, LENGTH);
	clock_t end = clock();
	return(double)(end - begin) / CLOCKS_PER_SEC;
}

double merge_(int* A, int LENGTH) {
	clock_t begin = clock();
	mergeSort(A, 0, LENGTH);
	clock_t end = clock();
	return (double)(end - begin) / CLOCKS_PER_SEC;
}

void makeOutput(const char* method, int* A, int LENGTH, double time_taken) {
	FILE* fq = fopen("./info.log", "a");
	if (fq != NULL) {
		fprintf(fq, "\r\n---------------------------\r\n");
		fprintf(fq, "Method:\t%s\r\n", method);
		fprintf(fq, "Size:\t%d\r\n", LENGTH);
		fprintf(fq, "Time:\t%f\r\n", time_taken);
		fprintf(fq, "---------------------------\r\n");
	}
	fclose(fq);
	
	// created sorted array
	fq = fopen("./sortedArray.log", "w");
	if (fq != NULL) {
		for (int i = 0; i < LENGTH; i++) {
			fprintf(fq, "%d\r\n", A[i]);
		}
	}
	fclose(fq);
	
	printf("---------------------------------");
	printf("\nMethod:\t%s\r\n", method);
	printf("Size:\t%d\r\n", LENGTH);
	printf("Time:\t%f\r\n", time_taken);
	printf("---------------------------------");
	
}

