#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(long primeCandidate)
{
	if (primeCandidate == 2)
	{
		// special case: 2 is prime
		return true;
	}
	else if (primeCandidate % 2 == 0)
	{
		// Even means not a prime
		return false;
	}
	for (long i = 3; i < primeCandidate; i += 2)
	{
		if (primeCandidate % i == (long) 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	printf("%o\n", isPrime(2));
}