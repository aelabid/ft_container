#include"../includes/vector.hpp"
#include"../utils/pair.hpp"
// #include"vector_it.hpp"
// int main()
// {
// 	//---------------------test vectors---------------------//
//     vector<int> v(5 , 10);
//     for(vector<int>::iterator it = v.begin(); it < v.end(); *it++)
//         std::cout<<*it<<" ";
// 	int n = 1;
//     int a[5] = {1, 2, 3, 4, 5};
 
//     // build a pair from two ints
//     pair<int, int*> p1 = make_pair(n, a+ 1);
//     std::cout << "The value of p1 is "
//               << "(" << p1.first << ", " << *(p1.second + 1) << ")\n";
// 	std::cout<<p1.first;
// 	// std::cout<<~int();
// }
template<typename A>
struct B { using type = typename A::type; };
 
template<
    class T,
    class U = typename T::type,    // SFINAE failure if T has no member type
    class V = typename B<T>::type> // hard error if T has no member type
                                   // (guaranteed to not occur via CWG 1227 because
                                   // substitution into the default template argument
                                   // of U would fail first)
void foo (int);
 
template<class T>
typename T::type h(typename B<T>::type);
 
template<class T>
auto h(typename B<T>::type) -> typename T::type; // redeclaration
 
template<class T>
void h(...) {}
 
using R = decltype(h<int>(0));