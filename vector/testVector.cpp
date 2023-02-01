#include"../includes/vector.hpp"
#include<vector>
int main()
{
    // std::vector<int> first(4,10);
    vector<int> v1(4,5);
    vector<int> v2(v1);
    // v1.a
    // first[0]=5;
    // second[0]=5;
    // vector<std::string> v1(5,"hello");
    vector<int>::size_type s;
    s=5;
    // for (int i = 0; i < 4; i++) {
        // std::cout<<"first = " << v1[i] << " ";
        std::cout <<"second = "<< s << " ";
    // }
    // std::vector<int> first;
    // std::vector<int> second (4,100);
    // std::cout<< first;


   /* assigned value to vector v1 */
  //  for (int i = 0; i < v1.size(); ++i)
  //     v1[i] = i + 1;
    // vector<int> v2(v1.begin(), v1.end());
    // v1.size()
    // for (int i = 0; i < 4; ++i)
      // std::cout << "v1.size = "<< v1.size() << "v2.size = "<< v2.size() << std::endl;
}

// C++ program to illustrate default
// constructor without 'explicit'
// keyword
// #include <iostream>
// using namespace std;

// class Complex {
// private:
// 	int real;
// 	double imag;

// public:

// 	// Parameterized constructor
// 	explicit Complex(int r = 0) : real(r)
// 	{
// 	}

// 	// A method to compare two
// 	// Complex numbers
// 	bool operator == (Complex rhs)
// 	{
// 		return (real == rhs.real);
// 	}
// };

// // Driver Code
// int main()
// {
// 	// a Complex object
// 	Complex com1(3.0, 0.0);

// 	if (com1 == (Complex)3.0)
// 		cout << "Same";
// 	else
// 		cout << "Not Same";
// 	return 0;
// }
