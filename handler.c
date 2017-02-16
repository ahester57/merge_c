#include <stdlib.h>
#include <stdio.h>
#include "handler.h"

// file helper

int getNumLines(FILE* fp) {
	int n = 0;
	char* line = malloc(12*sizeof(char));
	
	fseek(fp, 0, SEEK_SET);
	while (fgets(line, 12, (FILE*)fp)) {
		n++;
	}
	free(line);
	return n;
}

void setArray(int* A, FILE* fp) {
	int n = 0;
	char* line = malloc(12*sizeof(char));

	fseek(fp, 0, SEEK_SET);
	while (fgets(line, 12, (FILE*)fp)) {
		A[n] = atoi(line);	// hope for numbers
		//printf("%d, ", A[n]);
		n++;
	}	
	free(line);
}
