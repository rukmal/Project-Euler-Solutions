/**
 * Author: Rukmal Weerawarana
 *
 * This solution is a part of my collection of solutions to the Project Euler
 * problem set (http://projecteuler.net).
 *
 * For the full collection, see: http://rukmal.github.io/Project-Euler-Solutions
 *
 * This is the solution to problem #001. See: http://projecteuler.net/problem=1
 */

#include <stdio.h>

int main()
{
	int totalSum = 0;
	for (int i = 0; i < 1000; i++)
	{
		if ((i % 5 == 0) || (i % 3 == 0))
		{
			totalSum += i;
		}
	}
	printf("%i\n", totalSum);
}