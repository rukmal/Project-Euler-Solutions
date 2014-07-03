/**
 * Author: Rukmal Weerawarana
 *
 * This solution is a part of my collection of solutions to the Project Euler
 * problem set (http://projecteuler.net).
 *
 * For the full collection, see: http://rukmal.github.io/Project-Euler-Solutions
 *
 * This is the solution to problem #003. See: http://projecteuler.net/problem=3
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int nextPrimeHelper(int candidate)
{
	for (int i = 3; i < candidate; i += 2)
	{
		if (candidate % i == 0)
		{
			return nextPrimeHelper(candidate + 2);
		}
	}
	return candidate;
}

int nextPrime(int currentPrime)
{
	if (currentPrime == 2)
	{
		return 3;
	}
	else
	{
		return nextPrimeHelper(currentPrime + 2);
	}
}

int main()
{
	long const VALUE = 600851475143;
	long currentValue = VALUE;
	long currentPrime = 2;
	int counter = 0;
	while (true)
	{
		printf("%lo\n", currentValue);
		if (currentPrime == VALUE)
		{
			printf("%lo\n", currentPrime);
			break;
		}
		else if (VALUE % currentPrime == 0)
		{
			currentValue = currentValue / currentPrime;
		}
		else if (counter > 1)
		{
			currentPrime = 2;
			counter = 0;
		}
		else if (VALUE % currentPrime != 0)
		{
			currentPrime = nextPrime(currentPrime);
		}
	}
}