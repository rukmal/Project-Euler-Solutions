/**
 * Author: Rukmal Weerawarana
 *
 * This solution is a part of my collection of solutions to the Project Euler
 * problem set (http://projecteuler.net).
 *
 * For the full collection, see: http://rukmal.github.io/Project-Euler-Solutions
 *
 * This is the solution to problem #004. See: http://projecteuler.net/problem=4
 */

#include <stdio.h>

 int main()
 {
	int currentmax = 0;
 	for (int i = 0; i < 1000; i++)
 	{
 		for (int j = 0; j < 1000; j++)
 		{
 			if (i * j > currentmax)
 			{
 				currentmax = i * j;
 			}
 		}
 	}
 	printf("%i\n", currentmax);
 }