#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <iostream>



/// ------------------------------------------------------------------------------------
//
//	Multi-dimensional array tricks
//
/// ------------------------------------------------------------------------------------

void testMultiArray()
{
	using namespace std;

	{
		int a[] = { 1, 2, 3, 4 };
		cout << (*(&a + 1))[-1] << endl; // 4
	}

	{
		//
		//        | a1 | --> [ 1 x x x ]
		//  a --> | a2 | --> [ 2 x x x ]
		//        | a3 | --> [ 3 x x x ]
		//
		int a[3][4] = { {1}, {2}, {3} }; // type of a: int** 

		//       | b1 | --> [ .. ]
		// b --> | b2 | --> [ .. ]
		//       | b3 | --> [ .. ]
		//       | b4 | --> [ .. ]
		//
		int *b[4];   // eqv to int* b[4]; type of b: int** ?

		// c --> temp --> [ c1 c2 c3 c4 ]
		int (*c)[4]; // c is a pointer to array of 4; type of c: int** ?

		b[0] = a[1];
		cout << b[0][0] << endl;	// 2 ?
		c = &a[2];
		cout << c[0][0] << endl;	// 3 ?
	}
}


/// ------------------------------------------------------------------------------------
//
///	Pass a native array in a wrong way
//
/// ------------------------------------------------------------------------------------

void arraySize(int ar[])
{
	std::cout << sizeof(ar) / sizeof(*ar) << std::endl;
}

void arraySize2(int* const ar)
{
	std::cout << sizeof(ar) / sizeof(*ar) << std::endl;
}

void showArraySize()
{
	int nums[] = { 1, 2, 3 };
	std::cout << "array size: " << sizeof(nums)/sizeof(*nums) << std::endl; // array size: 3
	
	arraySize(nums);		// Undefined or unspecified behavior
	arraySize2(nums);		// Undefined or unspecified behavior
}


/// ------------------------------------------------------------------------------------
//
///	Pass a native array in the right way
//
/// ------------------------------------------------------------------------------------

int sumArray(int* a, int sz)
{
	if (sz <= 0)
		return 0;
	else
	{
		--sz;
		return a[sz] + sumArray(a, sz);
	}
}

void testSumArray()
{
	int a[] = { 1, 2, 3 };
	int res = sumArray(a, 3);
}


#endif
