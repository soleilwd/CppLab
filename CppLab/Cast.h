#ifndef __CONVERSION_H__
#define __CONVERSION_H__



// ------------------------------------------------------------------------------------
//
// Test various scenarios on static_cast
// Think:	Which criteria must T and U satisfy in order for below static_cast to succeed?
//				U u = static_cast<U>(t);
//				U* u = static_cast<U*>(t);
//
// ------------------------------------------------------------------------------------
void testStaticCast()
{
	{
		//
		// Object up cast with static_cast, resulting in object slicing.
		// Implicit conversion can also do the job.
		//
		Person p(1);
		Man m(1,1);
		p = static_cast<Person>(m); // Object down cast, OK. Is it eqv to "p = m;"?
									// Object up cast would result in error.

		// Think:
		// What's behind the scene in above example? Does compiler convert m to Person object, then invoke assignment operator on Person?
		// How about Person new_person = m;
	}
	{
		//
		// Up cast with static_cast
		// Think: is implicit conversion allowed?
		//
		Man* mm = new Man(2,1);
		Person* pm = static_cast<Person*>(mm);
	}
	{
		//
		// Down cast with static_cast
		// Think: what's the difference with dynamic_cast
		//
		Person* pm = new Man(2,1);
		Man* mm = static_cast<Man*>(pm);
	}
}



// ------------------------------------------------------------------------------------
//
// Test various scenarios on const_cast
//
// ------------------------------------------------------------------------------------
void testConstCast()
{
	/// Case 1: const T*
	{
		//
		// const_cast an object doesn't make any sense - a const object could be directly assigned to a non-const variable.
		// const_cast is designed to work on pointers or references to a const object ("const T*" or "const T&")
		//

		const Person person(1);

		// Person p2 = const_cast<Person>(person);	// Error
		Person* p = const_cast<Person*>(&person);
		Person& r = const_cast<Person&>(person);
	}

	/// Case 2: T* const
	{
		//
		// There seems no direct way if we want to point s1 to a different string...
		//

		char s[] = "abc";						// s is "char* const"
		//char* ptr = s;						// OK, since data pointed by s isn't const

		/*
		char* const* p1 = &s;
		char** p2 = const_cast<char**>(p1);
		*p2 = NULL;
		*/
	}

	/// Case 3: const T* const
	{
		const char s[] = "abc";				// s is "const char* const";
		//s[1] = 'c';						// Compile-time error

		const char* p1 = const_cast<const char*>(s);	// Cast 2nd const away, e.g., const char*
		char* const p2 = const_cast<char* const>(s);
		char* p3 = const_cast<char*>(s);
		p3[1] = 'c';							// Success
	}

	/// Exception to case 1
	{
		const char* str1 = "abc";
		char* str2 = const_cast<char*>(str1);	// Compile fine
		//str2[1] = 'c';						// Run-time error, since "abc" is in read-only data segment
	}
}

#endif
