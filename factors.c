#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * factor - calculate factorize numbers of a large number
 * @input: the large number
 * 
 * Return: no return
 */

void factor(unsigned long int input)
{
	unsigned long int ref = 2;
	unsigned long int num;
	while (input)
	{
		if (input % ref == 0)
		{
			/** our calculate*/
			num = input / ref;
			printf("%ld=%ld*%ld\n", input, num, ref);
			return;
		}
		else
			ref++;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s failed\n", argv[0]);
		return (1);
	}

	FILE *file = fopen(argv[1], "r");
	
	if (file == NULL)
	{
		printf("Error opening file: %s\n", argv[0]);
		return (1);
	}
	/**
	 * start of code
	 */

	char line[500];
	char* endptr;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		unsigned long int tep = strtoll(line, &endptr, 10);
		factor(tep);
	}
	fclose(file);
	return (0);
}
