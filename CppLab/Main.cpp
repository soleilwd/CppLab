//#include "StdAfx.h"
#include <iostream> 
#include <vector>
#include <cmath>
#include <limits>
#include "Test.h"


int main(int argc, char* argv[])
{
	using namespace std;

	test::testSizeof();

	/*
	vctor<int> v0;
	v0.reserve(8);
	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);

	vector<int> v1(5, 1);
	vector<int> v2(5, 1);

	v1 = v0;
	v2.assign(v0.begin(), v0.end());
	cout << v1.capacity() << " " << v2.capacity() << endl;
    */

/*
 	// float precision/comparison
	float d1 = 6.0f/2.0f;
	bool equal = d1 == 3.0f;	// true

	d1 = 6.0f/3.0f;
	equal = d1 == 2.0f;			// true

	float d2 = 600000.0f/300000.0f;
	equal = d1 == d2;			// true

	d1 = 1.0f/0.0f;
	d2 = 2.0f/0.0f;
	equal = d1 == d2;			// true


	d1 = 5.0f/2.0f;
	equal = d1 == 2.5f;
	d1 = 2.0f/5.0f;
	equal = d1 == 0.4f;
	d1 = 10.0f/3.0f;
	equal = d1 == 100000.f/30000.f;

	d1 = 1.0f/1000000.0f;
	d2 = 0.0000000001f/0.0001f;
	equal = d1 == d2;
*/

	return 0;
}

