#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

/**
 * factor - calculate factorize numbers of a large number
 * @input: the large number
 * 
 * Return: no return
 */

void factor(char input[])
{
	long long int ref = 2;
	long long int num;
	long long int input_num = strtoll(input, NULL, 10);
	
	
	while (input)
	{
		if (input_num % (ref) == 0)
		{
			/** our calculate*/
			(num) = input_num / (ref);
			printf("%lld=%lld*%lld\n", input_num,
					num, ref);
			return;
		}
		else
			ref++;
	}
	/* not use */
	for (ref = 1; ref <= atoll(input); ref += 2)
	{
		if (atoll(input) % (ref > 2 ? ref : 2) == 0)
		{
			num = atoll(input) / (ref > 2 ? ref : 2);
			printf("%lld=%lld*%lld\n", atoll(input),
					num, (ref > 2 ? ref : 2));
			return;
		}
		else
			;
	}

}

int main(int argc, char *argv[])
{
	clock_t start_time = clock();
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
		/*unsigned long int tep = strtoll(line, NULL, 10);
		factor(tep);
		*/
		/* printf(">>>%s", line); */
		factor(line);
	}
	fclose(file);
	/* clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("Execution time: %.6f seconds\n", elapsed_time); */
	return (0);
}
