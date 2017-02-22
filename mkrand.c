#include <stdio.h>
#include <stdlib.h>
#include "mkrand.h"
#define MAX_RND (65536*4096)
	// MAX_RND = 2 ** 28, about 256M

void mkList(long cnt, char* fName)
{
	long i;
	FILE *outfile;

	outfile = fopen (fName, "w");

	for (i = 0; i < cnt; i++) {
		fprintf (outfile, "%ld\n", rand () % MAX_RND);
		}
	fflush(outfile);
}
