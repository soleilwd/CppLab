#ifndef __FUNADDR_H__
#define __FUNADDR_H__

#include <iostream>


int add(int a, int b)
{
	return a + b;
}

class Item
{
public:
	void Update(int id)
	{ 
		mId = id;
	}

	int mId;
};

void testFunAddr()
{
	using namespace std;

	// print function address
	int (*fp)(int a, int b);
	fp = add;
	cout << "F1 address " << &add << endl;			// 0xaddress1
	cout << "F1 value " << add << endl;				// 0xaddress1
	cout << "Fp address " << &fp << endl;			// 0xaddress2
	cout << "Fp value " << fp << endl;				// 0xaddress1

	// Pointer to member
	int Item::*pItemId = &Item::mId;
	void (Item::*pUpdate)(int);		
	pUpdate = &Item::Update;			// This statement is needed, otherwise there's runtime error
										// complaining uninitialised variable

	Item t1;
	t1.*pItemId = 1;
	(t1.*pUpdate)(2);
}

#endif 
