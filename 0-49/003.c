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
bool isPrime(long n)
{
	if (n == 2)
	{
		// special case: 2 is a prime number
		return true;
	}
	for (long i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	long const VALUE = 600851475143;
	long currentMax = 0;
	for (long i = VALUE / 2; i > 0; i--)
	{
					printf("%lo\n", i);

		if ((VALUE % i == 0) && isPrime(i))
		{
			printf("%lo\n", i);
			break;
		}
	}
}