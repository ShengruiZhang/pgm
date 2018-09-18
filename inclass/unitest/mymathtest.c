#include "mymathtest.h"

unsigned int nPlus(void)
{
	int a = 1;

	for (a; a < 1000; ++a)
	{
		printf("a = %3d, nPlus3Sequence = %3d\n", a, nPlus3Sequence(a));
	}

	return 0;
}

unsigned int _fib(void)
{
	int b = 0;

	for (b; b <= 45; ++b)
	{
		printf("b = %3d, fib = %20d\n", b, (long)fib(b));
	}

	return 0;
}
