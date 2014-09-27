/*
 * Fibonacci.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: smart
 */

#include <vector>
#include <iostream>
using std::vector;

int naiveFibonacci(int n)
{
	if (n <= 2)
		return 1;
	else
		return naiveFibonacci(n-1) + naiveFibonacci(n-2);
}


//
//
int memorizedFibonacci(int n, std::vector<int>& slns)
{
	if (slns[n] != -1)
		return slns[n];

	if (n <= 2)
		slns[n] = 1;
	else
		slns[n] = memorizedFibonacci(n-1, slns) + memorizedFibonacci(n-2, slns);

	return slns[n];
}

/* non-recursive */
int iterativeFibonacci(int n)
{
	std::vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		if (i == 0 || i == 1)
			vec[i] = 1;
		else
			vec[i] = vec[i-1] + vec[i-2];
	}
	return vec[n-1];
}

void testFibonacci()
{
	int n = 5;
	std::vector<int> vec(n, -1);
	std::cout << memorizedFibonacci(n, vec) << std::endl;
}
