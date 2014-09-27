/*
 * Overload.h
 *
 *  Created on: Apr 21, 2014
 *      Author: smart
 */

#ifndef __OVERLOAD_H_
#define __OVERLOAD_H_

#include <iostream>
#include "Person.h"


namespace test {
	using std::cout;
	using std::endl;


	void Print(const Person& p)
	{
		std::cout << "Person: " << p.age << std::endl;
	}
	void Print(const Man& p)
	{
		std::cout << "Man: " << p.age << " " << p.length << std::endl;
	}
	void Print(Person* p)
	{
		std::cout << "Person: " << p->age << std::endl;
	}
	void Print(Man* p)
	{
		std::cout << "Man: " << p->age << " " << p->length << std::endl;
	}


	void testOverload()
	{
		Man m;
		Print(m);
		Print(&m);
		Person p;
		Print(p);
		Print(&p);
	}
}

#endif /* __OVERLOAD_H_ */
