#include <stdio.h>
#include <stdlib.h>
#include "merge.h"
#define MAX_RND (65536*4096)
	// MAX_RND = 2 ** 28, about 256M

void mkList(int cnt, char* fName)
{
	long i, cnt;
	FILE *outfile;

	outfile = fopen (fname, "w");

	for (i = 0; i < cnt; i++) {
		fprintf (outfile, "%ld\n", random () % MAX_RND);
		}

}
