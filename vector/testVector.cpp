// #include"../includes/vector.hpp"
// #include<iostream>
// #include<vector>
// #include<unistd.h>

//   // vector<int> myvector (10);   // 10 zero-initialized ints

//   // assign some values:
// int main()
// {
//   vector<int> foo (3,100);   // three ints with a value of 100
//   vector<int> bar (5,200);   // five ints with a value of 200

//   foo.swap(bar);

//   std::cout << "foo contains:";
//   for (unsigned i=0; i<foo.size(); i++)
//     std::cout << ' ' << foo[i];
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (unsigned i=0; i<bar.size(); i++)
//     std::cout << ' ' << bar[i];
//   std::cout << '\n';

// }

// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::vector<int> g1;

	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	cout << "Output of begin and end: ";
	for (vector<int>::iterator i = g1.begin(); i != g1.end(); ++i)
		cout << *i << " ";
    
	// cout << "\nOutput of cbegin and cend: ";
	// for (vector<int>::iterator i = g1.cbegin(); i != g1.cend(); ++i)
	// 	cout << *i << " ";

	// cout << "\nOutput of rbegin and rend: ";
	// for (vector<int>::iterator ir = g1.rbegin(); ir != g1.rend(); ++ir)
	// 	cout << *ir << " ";

	// cout << "\nOutput of crbegin and crend : ";
	// for (vector<int>::iterator ir = g1.crbegin(); ir != g1.crend(); ++ir)
	// 	cout << *ir << " ";

	return 0;
}
