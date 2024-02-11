#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void factor(unsigned long int num)
{
	unsigned long int ref = 2, tem1;

	while (ref <= num)
	{
		if (num % ref == 0)
		{
			tem1 = num / ref;
			printf("%ld=%ld*%ld\n", num, tem1, ref);
			return;
		}
		ref++;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Usage %s fail", argv[0]);
		return (1);
	}
	FILE *file = fopen(argv[1], "r");
	
	if(file == NULL)
	{
		printf("Error to open file: %s", argv[1]);
		return (1);
	}
	unsigned long int num;
	char line[100];

	if (fgets(line, sizeof(line), file) != NULL)
	{
		num = atoll(line);
		
	}
	factor(num);
	fclose(file);
	return (0);
}
