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

int nextPrime(int currentPrime)
{
	if (currentPrime == 2)
	{
		return 3;
	}
	int candidatePrime = currentPrime + 2;
	for (int i = 3; i < candidatePrime; i += 2)
	{
		if (candidatePrime % i == 0)
		{
			return nextPrime(candidatePrime);
		}
	}
	return candidatePrime;
}

int main()
{
	long const VALUE = 600851475143;
	long currentValue = VALUE;
	int currentPrime = 2;
	while (currentPrime != (int) currentValue)
	{
		if (currentValue % currentPrime == 0)
		{
			currentValue = currentValue / currentPrime;
			currentPrime = 2;
		}
		else
		{
			currentPrime = nextPrime(currentPrime);
		}
	}
	printf("%i\n", (int) currentValue);
}