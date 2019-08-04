#include <stdio.h>
#include <string.h>
#include "double.h"

int linenum = 0;

int getword(FILE *fp, char *buf, int size)
{
	int c = getc(fp);
	for (; c != EOF && isspace(c); c = getc(fp))
	{
		if (c == '\n')
		{
			++linenum;
		}
	}
	{
		int i = 0;
		for (; c != EOF && !isspace(c); c = getc(fp))
		{
			if (i < size - 1)
			{
				buf[i++] = tolower(c);
			}
		}
		if (i < size)
		{
			buf[i] = '\0';
		}
	}
	if (c != EOF)
	{
		ungetc(c, fp);
	}
	return buf[0] != '\0';
}

void doubleword(char *name, FILE *fp)
{
	char prev[128];
	char word[128];
	linenum = 1;
	prev[0] = '\0';
	while (getword(fp, word, sizeof(word)))
	{
		if (isalpha(word[0]) && strcmp(prev, word) == 0)
		{
			if (name)
			{
				printf("%s:", name);
			}
			printf("%d: %s\n", linenum, word);
		}
		strcpy(prev, word);
	}
}
