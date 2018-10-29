#include <stdio.h>
#define MAXLEN 5000

int escape(char source[], char out[]);
int unescape(char source[], char out[]);

int main()
{
	char string[MAXLEN] = "Hello\tworld!\nThis is on a\nNew Line!";
	char new[MAXLEN];
	char newnew[MAXLEN];

	printf("%s\n", string);
	escape(string, new);
	printf("%s\n", new);
	unescape(new, newnew);
	printf("%s\n", newnew);
}

int escape(char source[], char out[])
{
	int i, j;
	int c;

	j = 0;
	for (i = 0; (c = source[i]) != EOF; i++)
	{
		switch (c)
		{
			case '\n':
				out[j++] = '\\';
				out[j++] = 'n';
				break;
			case '\t':
				out[j++] = '\\';
				out[j++] = 't';
				break;
			default:
				out[j++] = c;
				break;
		}
	}
}

int unescape(char source[], char out[])
{
	int i, j;
	int c;

	j = 0;
	for (i = 0; (c = source[i]) != EOF; i++)
	{
		if (c == '\\')
		{
			switch (source[i + 1])
			{
				case 'n':
					out[j++] = '\n';
					break;
				case 't':
					out[j++] = '\t';
					break;
			}
		}
		else
			out[j++] = c;
	}
}
