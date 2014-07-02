/**
 * Author: Rukmal Weerawarana
 *
 * This solution is a part of my collection of solutions to the Project Euler
 * problem set (http://projecteuler.net).
 *
 * For the full collection, see: http://rukmal.github.io/Project-Euler-Solutions
 *
 * This is the solution to problem #002. See: http://projecteuler.net/problem=2
 */

#include <stdio.h>

int main ()
{
	int const MAX_VALUE = 4000000; // 4 million
	int currentTerm = 0;
	int sum = 0;
	int counter = 0;
	int oneBefore = 1;
	int twoBefore = 2;
	while (currentTerm < MAX_VALUE)
	{
		if (counter == 1)
		{
			currentTerm = twoBefore;
			sum += currentTerm;
		}
		else if (counter != 0)
		{
			int tmp = oneBefore;
			oneBefore = currentTerm;
			twoBefore = oneBefore;
			currentTerm = tmp + oneBefore;
			if (currentTerm % 2 == 0)
			{
				sum += currentTerm;
			}
		}
		counter += 1;
	}
	printf("%i\n", sum);
}