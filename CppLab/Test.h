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

		// Output are: 6 5 10 4 4
		char s1[] = "abcde"; // sizeof(s1) == 6, because of the last null character, however, strlen(s1) == 5
		char s2[] = { 'a', 'b', 'c', 'd', 'e' };
		char s3[10] = "abcde";
		char* p1 = s1;
		void* p2 = malloc(10);
		cout << sizeof(s1) << " ";
		cout << sizeof(s2) << " ";
		cout << sizeof(s3) << " ";
		cout << sizeof(p1) << " ";
		cout << sizeof(p2) << endl;
		free(p2);
	}

    void testIntegralType()
    {

        // size of data type
        // Output of gcc4.6.3-GNU/Linxu: 
        //   4 8 4 8
        std::cout << "long: " << sizeof(long) << std::endl;
        std::cout << "long long: " << sizeof(long long) << std::endl;
        std::cout << "float: " << sizeof(float) << std::endl;
        std::cout << "double: " << sizeof(double) << std::endl;

        // Note:
        //   2^31 = 2147483648
        //   2^32 = 4294967296
        // Output of gcc4.6.3-GNU/Linxu: 
        //   4294967295 4294967296
        //   4 8
        //   4294967295 0
        //   2147483647 -2147483648
        unsigned int ui = 4294967295;
        unsigned int uj = 4294967296;
        int si = 2147483647;
        int sj = 2147483648;
        std::cout << 4294967295 << " " << 4294967296 << endl;
        std::cout << sizeof(4294967295) << " " << sizeof(4294967296) << endl;
        std::cout << ui << " " << uj << endl;
        std::cout << si << " " << sj << endl;

        unsigned int i = -1;
        std::cout << i << std::endl;                                    // 4294967295

        float fm = std::numeric_limits<float>::max();
        cout << fm << ", size: " << sizeof(fm) << endl;					// 4
        cout << fm + 1.0 << ", size: " << sizeof(fm + 1.0) << endl;		// 8, elevation
        cout << fm * 2.0 << ", size: " << sizeof(fm * 2.0) << endl;		// 8, elevation

        float f1 = fm + 1.0;
        float f2 = fm * 2.0;
        cout << f1 << ", size: " << sizeof(f1) << endl;					// 4
        cout << f2 << ", size: " << sizeof(f2) << endl;					// 4, inf
        cout << std::isinf(f2) << " " << std::isnan(f2) << endl;        // true, false
    }
}

#endif
