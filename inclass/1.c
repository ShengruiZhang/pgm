#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 3

int main(int argc, char *argv[])
{
	printf("Number of Arguments: %d\n", argc - 1);

	if(argc != LIMIT + 1)
	{
		printf("Number of Arguments entered: %d\n", argc - 1);
		printf("Only %d Argument can be accepted\n", LIMIT);

		return 0;
	}
	
	int i = 1;

	for (i; i < argc; ++i)
	{
		printf("%s\n", argv[i]);
	}


	return 0;
}
