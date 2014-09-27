/*
 * DoublePointers.h
 *
 *  Created on: Jul 14, 2014
 *      Author: smart
 */

#ifndef __DOUBLEPOINTER_H_
#define __DOUBLEPOINTER_H_


void testDoublePointer()
{

	///--------------------------- Why conversion from int** to const int** is invalid?   -----------------------------------
	///---																												  ---
	// --- Note: const int** means pointer to pointer to const int, and either the two pointers are const				  ---
	//
	//
	//   		ppc ------>	pc -------> i									ppc ---\  pc ----> i
	//												can lead to 				    \         /
	//			pp	------> p												pp	----> p -----/
	//
	const int i = 1;
	const int* pc = &i;
	const int** ppc = &pc;
	int* p = 0;
	int** pp = &p;

	/*
		ppc = pp; // If conversion is allowed, then this statement is valid
		*ppc = pc;
		*p = 2;
	*/
}


#endif /* __DOUBLEPOINTERS_H_ */
