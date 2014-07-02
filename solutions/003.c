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

/**
 * Function to round to the nearest integer
 * @param  d Double to be rounded
 * @return   Rounded integer
 */
int roundToInt(double d)
{
	return (int) floor(d + 0.5);
}

/**
 * Function to determine if a number is prime
 * @param  n Number to check
 * @return   True if prime, false if not
 */
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
	long const VALUE = 600851475143;
	long const MIN = 5000;
	long currentMax = 0;
	long maxPrimeFactor = 0;
	for (long i = 1; i < VALUE / 2; i++)
	{
		printf("%lo\n", i);
		if (i < (long) roundToInt(sqrt(VALUE)))
		{		
			if (isPrime(i) && i > MIN)
			{
				maxPrimeFactor = i;
				break;
			}
		} else {
			break;
		}
	}
	printf("%lo\n", maxPrimeFactor);
}