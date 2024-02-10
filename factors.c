#include <stdio.h>
#include <stdlib.h>

/**
 * factor - calculate factorize numbers of a large number
 * @input: the large number
 * 
 * Return: no return
 */

void factor(long long int input)
{
	long long int ref = 2;
	long long int num;
	while (input)
	{
		if (input % ref == 0)
		{
			/** our calculate*/
			num = input / ref;
			printf("%lld=%lld*%lld\n", input, num, ref);
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
	int len = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		len++;
	}
	fclose(file);

	FILE *file1 = fopen(argv[1], "r");
	long long int num[len];

	int i = 0;
	while (fgets(line, sizeof(line), file1) != NULL)
        {
		long long int tep = strtoll(line, &endptr, 10);
		num[i] = tep;
		factor(num[i]);
		i++;
        }
	
	fclose(file1);
	return (0);
}
