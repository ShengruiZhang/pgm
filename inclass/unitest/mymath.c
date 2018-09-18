#include <stdio.h>
#include "mymath.h"

unsigned int nPlus3Sequence(unsigned int num) {
	unsigned int numIterations = 0;
	while (num != 1) {
		numIterations++;
		if (num % 2 == 0) {
			num = num / 2;
		}
		else {
			num = 3 * num + 1;
		}
	}
	return numIterations;
}


unsigned int fib(unsigned int num) {
	if (num == 0 | num == 1) {
		return 1;
	}

	return fib(num - 1) + fib(num - 2);
}

double logisticMap(double initialCondition) {
	for (unsigned int i = 0; i < 1000; i++) {
		initialCondition = 3.0*(1 - initialCondition)*initialCondition;
	}

	return initialCondition;
}

void reverseArray(unsigned int *x, unsigned int numElements) {
	unsigned int tempVal = 0;
	unsigned int index = 0;
	while (index != numElements / 2) {
		tempVal = x[index];
		x[index] = x[numElements - index - 1];
		x[numElements - index - 1] = tempVal;
	}
}
