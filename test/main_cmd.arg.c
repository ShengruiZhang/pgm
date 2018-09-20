#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _dis(int count, char *args[])
{
	for (int i = 1; args[i] != NULL; ++i)
	{
		printf("%s\n", args[i]);
	}

	return;
}

int main(int argc, char *argv[])
{

	_dis(argc, argv);

	return 0;
}
