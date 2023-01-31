#include"../includes/vector.hpp"
// #include<vector>
int main()
{
    // std::vector<int> first(4,10);
    vector<int> second (4,10);
    // first[0]=5;
    // second[0]=5;
    for (int i = 0; i < 4; i++) {
        // std::cout<<"first = " << first[i] << " ";
        std::cout <<"second = "<< second[i] << " ";
    }
    // std::vector<int> first;
    // std::vector<int> second (4,100);
    // std::cout<< first;
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
