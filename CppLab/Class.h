#ifndef __CLASS_H__
#define __CLASS_H__

#include <iostream>



/// ------------------------------------------------------------------------------------
///
///	Test default initialisation of a reference data member
///
/// ------------------------------------------------------------------------------------

class ClassWithRefMember
{
public:
	int mInt;
	char& mChar;
};

void testClassWithRef()
{
	char c = 'c';
	ClassWithRefMember obj = { 1, c };
	obj.mChar = 'd';
}



/// ------------------------------------------------------------------------------------
///
///	Test various scenarios of default initialisation and value initialisation
///
/// ------------------------------------------------------------------------------------
using std::cout;
using std::endl;

void testDefaultInitialisation() {

	{
		//
	 	// test value initialisation
		//
		int* i1 = new int;
		int* i2 = new int();

		Person1* p1 = new Person1;
		Person1* p2 = new Person1();
		Person2* p3 = new Person2;
		Person2* p4 = new Person2();

		// Outputs:	VS2012_Express						GCC4.8.3_Cygwin
		//			random_value	0					0	0
		//			random_value	0					0	0
		//			random_value	random_value		0	0
		cout << *i1 << " " << *i2 << endl;
		cout << p1->age << " " << p2->age << endl;
		cout << p3->age << " " << p4->age << endl;

		delete p1;
		delete p2;
		delete p3;
		delete p4;
	}

	{
		//
		// Test default construction
		//
		Person1 o1;
		Person1* ptr1 = new Person1;
		static Person1 so1;
		Person1 ar1[3];
		Person1* ar_ptr1 = new Person1[3];
		std::vector<Person1> vec1(3);
																			// VS2012_Express		GCC4.8.3_Cygwin
		cout << "Person 1: " << o1.age << endl;								// runtime_error		random_value
		cout << "Person 1 on heap: " << (*ptr1).age << endl;				// random_value			random_value
		cout << "Person 1 static: " << so1.age << endl;						// 0					0
		cout << "Person 1 array[0] " << ar1[0].age << endl;					// random value			random_value
		cout << "Person 1 heap array[0]: " << ar_ptr1[0].age << endl;		// random_value			0
		cout << "Person 1 vector[0]: " << vec1[0].age << endl;				// 0					0

		Person2 o2;
		Person2* ptr2 = new Person2;
		static Person2 so2;
		Person2 ar2[3];
		Person2* ar_ptr2 = new Person2[3];
		std::vector<Person2> vec2(3);

		cout << "Person 2: " << o2.age << endl;								// runtime_error		random_value
		cout << "Person 2 on heap: " << (*ptr2).age << endl;				// random_value			0
		cout << "Person 2 static: " << so2.age << endl;						// 0					0
		cout << "Person 2 array[0] " << ar2[0].age << endl;					// random_value			random_value
		cout << "Person 2 heap array[0]: " << ar_ptr2[0].age << endl;		// random_value			0
		cout << "Person 2 vector[0]: " << vec2[0].age << endl;				// random_value			random_value


		delete ptr1;
		delete[] ar_ptr1;
		delete ptr2;
		delete[] ar_ptr2;
	}
}

#endif
