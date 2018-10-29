#include <stdio.h>
#define LIMIT 5000

int getfile(char line[], int lim);

int main()
{
	char file[LIMIT];
	char out[LIMIT];
	int com; // Will be non-zero (true) if we are inside a comment
	int i, c, l;

	printf("Enter some C code with comments:\n");
	getfile(file, LIMIT);

	l = i = 0;
	while ((c = file[l]) != EOF)
	{
		if (c == '/' && file[++l] == '/') // We are in a single-line comment
			while ((c = file[++l]) != '\n')
				; // Do not copy to output if we're in a comment
		if (c == '/' && file[++l] == '*') // We have begun a multi-line comment
			while ((c = file[++l]) != '*' && file[++l] != '/')
				; // Do not copy to output if we're in a comment
		out[i++] = c;
	}
	
	printf("Output:\n%s\n", out);
	return 0;
}

int getfile(char line[], int lim)
{
	int c, i;

	for (i = 0; (c = getchar()) != EOF; ++i)
		if (i < lim - 1)
			line[i] = c;
	line[++i] = '\0';
}
