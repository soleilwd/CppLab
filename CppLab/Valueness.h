/*
 * Valueness.h
 *
 *  Created on: May 21, 2014
 *      Author: smart
 */

#ifndef __VALUENESS_H_
#define __VALUENESS_H_

#include <iostream>
#include <string>


namespace test {

// ----------------------------------------------------------------------------------------------
// supporting classes
// ----------------------------------------------------------------------------------------------
class MyInt
{
public:
	int val;

	MyInt(int v) : val(v)
	{}

	MyInt operator++(int)
	{
		MyInt temp = *this;
		this->operator ++();
		return temp;
	}

	MyInt& operator++()
	{
		++val;
		return *this;
	}
};


// ----------------------------------------------------------------------------------------------
// supporting functions
// ----------------------------------------------------------------------------------------------

int add(int a, int b)
{
	return a + b;
}

std::string name()
{
	return "name";
}

const std::string surname()
{
	return "surname";
}

void update(std::string& str2updae)
{
	str2updae.append("abc");
}

void print(const std::string& str)
{
	std::cout << str << std::endl;
}

int returnAnInt()
{
	int i = 0;
	return i;
}

const MyInt operator+(const MyInt& l, const MyInt& r)
{
	return MyInt(l.val + r.val);
}

MyInt operator*(const MyInt& l, const MyInt& r)
{
	return MyInt(l.val * r.val);
}



// ----------------------------------------------------------------------------------------------
// test
// ----------------------------------------------------------------------------------------------

void testValueness()
{

	//--------------------------------  built-in type   ---------------------------------------

	int a = 1, b = 2;
	// int& i = a + b; 			// cannot compile, a+b is rvalue
	const int& i = a + b;
	// int& j = returnAnInt(); 	// cannot compile, a+b is rvalue
	const int& j = returnAnInt();

	// a + b = 4; 				// cannot compile, a+b is rvalue
	// int c = ++(a + b); 		// cannot compile, a+b is rvalue
	// returnAnInt() = 2; 		// cannot compile, function return value is rvalue
	// int c = ++(returnAnInt()); // cannot compile, function return value is rvalue

	// add(a, b) = 4;			// cannot compile, rvalue
	// ++(add(a, b));			// cannot compile, rvalue

	//--------------------------------  user defined type   ----------------------------------

	// std::string& n = name(); // cannot compile, returned value is rvalue
	const std::string& n = name();

	name().append("abc"); 		///***** abnormally, it could compile, event if it's rvalue *****///
	name() = "abc";				///***** abnormally, it could compile, event if it's rvalue *****///
	// surname().append("w"); 	// cannot compile, const qualifier

	//update("abc"); 			// can not compile, implicit conversion generates temporary object, binding to non-const reference is forbidden
	print("abc");    			// ok, temporary string bound to const reference

	//--------------------------------  user defined type   ----------------------------------

	MyInt ma(1), mb(2);
	// (ma + mb) = MyInt(3);	// cannot compile, const violation
	(ma * mb) = MyInt(3);		///***** abnormally, it could compile, event if it's rvalue *****///
	// ++(ma + mb);				// cannot compile, const violation
	++(ma * mb);				///***** abnormally, it could compile, event if it's rvalue *****///

}

}

#endif /* __VALUENESS_H_ */
