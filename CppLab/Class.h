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

	/*
	 	// value initialisation
		int* i1 = new int;
		int* i2 = new int();
		cout << *i1 << " " << *i2 << endl;

		Person* p1 = new Person;
		Person* p2 = new Person();

		cout << p1->age << " " << p2->age << endl;

		delete p1;
		delete p2;
	*/


	Person1 o1;
	Person1* ptr1 = new Person1();
	static Person1 so1;
	Person1 ar1[3];
	Person1* ar_ptr1 = new Person1[3];
	std::vector<Person1> vec1(3);

	cout << "Person 1: " << o1.age << endl;								// random value
	cout << "Person 1 on heap: " << (*ptr1).age << endl;				// 0
	cout << "Person 1 static: " << so1.age << endl;						// 0
	cout << "Person 1 array[0] " << ar1[0].age << endl;					// random value
	cout << "Person 1 heap array[0]: " << ar_ptr1[0].age << endl;		// 0
	cout << "Person 1 vector[0]: " << vec1[0].age << endl;				// 0

	Person2 o2;
	Person2* ptr2 = new Person2();
	static Person2 so2;
	Person2 ar2[3];
	Person2* ar_ptr2 = new Person2[3];
	std::vector<Person2> vec2(3);

	cout << "Person 2: " << o1.age << endl;								// random value
	cout << "Person 2 on heap: " << (*ptr1).age << endl;				// 0
	cout << "Person 2 static: " << so1.age << endl;						// 0
	cout << "Person 2 array[0] " << ar1[0].age << endl;					// random value
	cout << "Person 2 heap array[0]: " << ar_ptr1[0].age << endl;		// 0
	cout << "Person 2 vector[0]: " << vec1[0].age << endl;				// 0


	delete ptr1;
	delete[] ar_ptr1;
	delete ptr2;
	delete[] ar_ptr2;
}

#endif
