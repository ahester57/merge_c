#include <stdio.h>
#include <stdlib.h>
#define MAX_RND (65536*4096)
	// MAX_RND = 2 ** 28, about 256M

int main (int argc, char *argv[])
{
	long i, cnt;
	FILE *outfile;

	if (argc != 3) {
		printf ("Usage: %s count out_file\n", argv[0]); exit (1);}

	cnt = strtol (argv[1], NULL, 10);
	outfile = fopen (argv[2], "w");

	for (i = 0; i < cnt; i++) {
		fprintf (outfile, "%ld\n", random () % MAX_RND);
		}

	exit (0);
}
