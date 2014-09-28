#ifndef __TEST_H__
#define __TEST_H__

#include <cstdlib>
#include "Person.h"
#include "Array.h"
#include "Cast.h"
#include "Class.h"
#include "Const.h"
#include "DoublePointer.h"
#include "FunAddr.h"
#include "Overload.h"
#include "Valueness.h"



namespace test{

/// ----------------------------------------------------------------------------------------------------------------
///
/// Test basic C/C++ features
///
/// ----------------------------------------------------------------------------------------------------------------

	void testSizeof() {
		int ia[3] = { 1, 2, 3 };
		int* ib = ia;
		Person* pp = new Person();
		Person* pm = new Man();
		Man* mm = static_cast<Man*>(pm);
		// Output are: 12 4 4 4 8
		cout << "Size of array a: " << sizeof(ia) << endl;
		cout << "Size of array b: " << sizeof(ib) << endl;
		cout << "Size of Person: " << sizeof(*pp) << endl;
		cout << "Size of Person: " << sizeof(*pm) << endl;
		cout << "Size of Person: " << sizeof(*mm) << endl;

		// Output are: 4 3 10 4 4
		char s1[] = "abc"; // sizeof(s1) == 4, because of the last null character
		char s2[] = { 'a', 'b', 'c' };
		char s3[10] = "abc";
		char* p1 = s1;
		void* p2 = malloc(10);
		cout << sizeof(s1) << " ";
		cout << sizeof(s2) << " ";
		cout << sizeof(s3) << " ";
		cout << sizeof(p1) << " ";
		cout << sizeof(p2) << endl;
		free(p2);
	}

}

#endif
