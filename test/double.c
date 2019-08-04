#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "double.h"

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL)
		{
			fprintf(stderr, "%s: can't open '%s' (%s)\n", argv[0], argv[i], strerror(errno));
			return EXIT_FAILURE;
		}
		else
		{
			doubleword(argv[i], fp);
			fclose(fp);
		}
	}
	if (argc == 1)
	{
		doubleword(NULL, stdin);
	}
	return EXIT_SUCCESS;
}
