//#include "StdAfx.h"
#include <iostream> 
#include <vector>

#include "Test.h"


int main(int argc, char* argv[])
{
	using namespace std;

	vector<int> v0;
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

	return 0;

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

/*
	double d = 10.1;
	int i = 10;
	cout << sizeof(d/i) << endl;
	cout << sizeof(i/d) << endl;

	float fm = numeric_limits<float>::max();
	cout << fm << ", size: " << sizeof(fm) << endl;					// 4
	cout << fm + 1.0 << ", size: " << sizeof(fm + 1.0) << endl;		// 8, elevation
	cout << fm * 2.0 << ", size: " << sizeof(fm * 2.0) << endl;		// 8, elevation

	float f1 = fm + 1.0;
	float f2 = fm * 2.0;
	cout << f1 << ", size: " << sizeof(f1) << endl;					// 4
	cout << f2 << ", size: " << sizeof(f2) << endl;					// 4, inf
	cout << std::isinf(f2) << " " << std::isnan(f2) << endl;
*/

/*
	 unsigned int i = 1;
	 unsigned int j = -1;
	 unsigned int ui = 2147483648;
	 unsigned int uj = 2147483649;
	 int si = 2147483648;
	 int sj = 2147483649;
	 std::cout << ui << " " << uj << endl;
	 std::cout << si << " " << sj << endl;
	 std::cout << 2147483648 << " " << 2147483649 << endl;
*/
}

