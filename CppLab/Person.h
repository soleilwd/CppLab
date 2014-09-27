#ifndef __PERSON_H__
#define __PERSON_H__


class Person {
public:
	int age;
	Person() : age(0)
	{
		std::cout << "Person constructed" << std::endl;
	}
	Person(int a) :	age(a)
	{
		std::cout << "Person constructed. Age: " << age << std::endl;
	} 
	Person(const Person& rhs)
	{
		age = rhs.age;
		std::cout << "Person copy constructed" << std::endl;
	}
	void Update(int a)
	{
		age = a;
	}
};


class Man: public Person {
public:
	int length;
	Man() : Person(), length(0)
	{
		std::cout << "Man constructed" << std::endl;
	}
	Man(int a, int l) : Person(a), length(l) 
	{
		std::cout << "Man constructed. Length: " << length << std::endl;
	} 
};


class Person1 {
public:
	int age;
};

class Person2 {
public:
	int age;
	Person2() {
	}
};

#endif