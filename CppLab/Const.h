/*
 * Constness.h
 *
 *  Created on: May 21, 2014
 *      Author: smart
 */

#ifndef __CONST_H_
#define __CONST_H_

#include "Person.h"


namespace test
{


	//
	// create pointers on const object
	//
	void createPointersOnConst()
	{
		const int i = 2;
		const int* p = &i;
		const int& r = i;

		// However, we can not assign a ptr_to_const to a normal ptr, like below:
		//int* p2 = &i;
		//int* p2 = p;
	}

	//
	// create const pointers on non-const object
	//
	void createConstPointers()
	{
		//--------------------------------------------------------------------------------------------------------------------------------
		//
		// Const qualifier on a pointer/reference is a promise that we do not intend to modify the object via this pointer/reference,
		// It does not enforce the object being pointed to a const object. This is the the rational behind pass-by-reference-to-const.
		//
		//--------------------------------------------------------------------------------------------------------------------------------

		int i = 2;
		const int* p = &i; 	// assign "int*" to "const int*"
		const int& r = i;
	}


}

#endif /* CONSTNESS_H_ */
